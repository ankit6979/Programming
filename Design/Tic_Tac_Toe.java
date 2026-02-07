/*
1. Enact th egame of Tic Tac Toe between two players.
2. The game is played on a grid that's 3 squares by 3 squares.
3. One player is X, and the other player is O. Players take turns putting their marks in empty squares.

1. Strategy pattern is used to define different strategies for players.
2. State design pattern for game flow managemnet.
3. Observer pattern to notify players of game state changes.
4. Fcatory pattern to create players.
*/

enum Symbol {
    X, O, EMPTY;
}

public class Board {
    private Symbol[][] grid;
    public Board(int size) { 
        grid = new char[size][size]; 
        for(int row = 0; row < size; row++){
            for(int col = 0; col < size; col++){
                grid[row][col] = Symbol.Empty;
            }
        }
    }
}

public class Player {
    Symbol symbol;
	    PlayerStrategy playerStrategy;

    public Player (Symbol symbol , PlayerStrategy playerStrategy){
        this.symbol = symbol;
        this.playerStrategy = playerStrategy;
    }

    public Symbol getSymbol(){
        return symbol;
    }

    public PlayerStrategy getPlayerStrategy(){
        return playerStrategy;
    }
}

public class Position {
	    public int row;
	    public int col;

	    // Constructor to initialize the position
	    public Position(int row, int col) {
	        this.row = row;
	        this.col = col;
	    }

	    // Optional: Override toString for better debugging or printing
	    @Override
	    public String toString() {
	        return "(" + row + ", " + col + ")";
	    }

	    // Optional: Equals and hashCode if you ever want to compare positions or use in collections
	    @Override
	    public boolean equals(Object obj) {
	        if (this == obj) return true;
	        if (!(obj instanceof Position)) return false;
	        Position other = (Position) obj;
	        return this.row == other.row && this.col == other.col;
	    }

	    @Override
	    public int hashCode() {
	        return 31 * row + col;
	    }
}

public interface GameState {
    void next(GameContext context);
}

public interface PlayerStrategy {
    Position makeMove(Board board);
}

public class HumanPlayerStragety implements PlayerStrategy {
    private Scanner scanner;
    private String playerName;

    public HumanPlayertrategy(String playerName) {
        this.playerName = playerName;
        this.scanner = new Scanner(System.in);
    }
    @Override
    public Position makeMove(Board board) {
        while(true) {
            System.out.printf("%s, enter your move (row and column): ", playerName);
            try {
                int row = scanner.nextInt();
                int col = scanner.netxInt();
                Position move = new Poosition(row, col);

                if(board.isValidMove(move)) {
                    return move;
                } else {
                    System.out.println("Invalid move. Try again.");
                }
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter numbers for row and column.");
                scanner.nextLine(); // Clear the invalid input
            }
        }
    }
}

public class XTurnState implements GameState {
    @Override
    public void next (GameContext context) {
        context.setState(new OturnState());
    }

    public boolean isGameOver() {
        return false;
    }
}

public class OTurnState implements GameState {
    @Override
    public void next (GameContext context) {
        context.setState(new XturnState());
    }

    public boolean isGameOver() {
        return false;
    }
}

public class XWonState implements GameState {
    @Override
    public void next (GameContext context) {
        // no next state
    }

    public boolean isGameOver() {
        return true;
    }
}

public class OWonState implements GameState {
    @Override
    public void next (GameContext context) {
        // no next state
    }

    public boolean isGameOver() {
        return true;
    }
}

public class GameContext {
    private GameState currentState;

    public GameContext() {
        currentState = new XTurnState();
    }

    public void setState(GameState state) {
        this.currentState = state;
    }

    public void next() {
        currentState.next(this);
    }

    public boolean isGameOver() {
        return currentState.isGameOver();
    }

    public GameState getCurrentState() {
        return currentState;
    }
}

public class Board {
    private final int rows;
    private final int columns;
    private Symbol[][] grid;

    public Board(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        grid = new Symbol[rows][columns];

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                grid[i][j] = Symbol.EMPTY;
            }
        }
    }

    public boolean isValidMove(Position pos) {
        return pos.row >= 0 && pos.row < rows && pos.column >= 0 && pos.column < columns && grid[pos.row][pos.column] == Symbol.EMPTY;
    }

    public void makeMove(Position pos, Symbol symbol) {
        grid[pos.row][pos.column] = symbol;
    }

    public void checkGameState (GameContext context) {
        for (int i = 0; i < rows; ++i) {
            if(grid[i][0] != Symbol.EMPTY && isWinningLine(grid[i])) {
                context.next();
                return;
            }
        }

        for (int i = 0; i < columns; ++i) {
            Symbol[] column = new Symbol[rows];

            for (int j = 0; j < rows; ++j) {
                column[j] = grid[i][j];
            }

            if(column[0] != Symbol.EMPTY && isWinningLine(column)) {
                context.next();
                return;
            }
        }

        Symbol diagonal1 = new Symbol[Math.min(rows, columns)];
        Symbol diagonal2 = new Symbol[Math.min(rows, columns)];

        for (int i = 0; i < Math.min(rows, columns); ++i) {
            diagonal1[i] = grid[i][i];
            diagonal2[i] = grid[i][columns - 1 - i];
        }

        if(diagonal1[0] != Symbol.EMPTY && IsWinningLine(diagonal1)) {
            context.next();
            return;
        }

        if(diagonal2[0] != Symbol.EMPTY && IsWinningLine(diagonal2)) {
            context.next();
            return;
        }

        private boolena IsWinningLine(Symbol[] line) {
            Symbol first = line[0];

            for (Symbol s : line) {
                if(s != first) {
                    return false;
                }
            }

            return true;
        }
    }
}

interface BoardGames {
    void play();
}

public class TicTacToe implements BoardGames {
    private Board board;
    private final Player playerX;
    private final Player playerO;
    private Player currentPlayer;
    private GameContext gameContext;

    public TicTacToe(PlayerStrategy xStrategy, PlayerStrategy oStrategy, int rows, int columns) {
        board = new Board(rows, columns);
        playerX = new Player(Symbol.X, xStrategy);
        playerO = new Player(Symbol.O, oStrategy);
        currentPlayer = playerX;
        gameContext = new GameContext();
    }

    @Override
    public void play() {
        do {
            board.printBorad();

            Position move = currentPlayer.makeMove(board);
            board.makeMove(move, currentPlayer.getSymbol());

            board.checkGameState(gameContext);
            switchPlayer();
        } while(!gameContext.isGameOver());

        announceResult();
    }

    private void switchPlayer() {
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

    private void announceResult() {
        GameState state = gameContext.getCurrentState();

        if (state instanceof XWonState) {
            System.out.println("Player X wins");
        }

        else if (state instanceof OWonState) {
            System.out.println("Player O wins");
        }
        else {
            System.out.println("It's a draw");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        PlayerStrategy playerXStrategy = new HumanPlayerStragety("Player X");
        PlayerStrategy playerOStrategy = new HumanPlayerStragety("Player O");

        TicTacToe game = new TicTacToe(playerXStrategy, playerOStrategy);
        game.play();
    }
}