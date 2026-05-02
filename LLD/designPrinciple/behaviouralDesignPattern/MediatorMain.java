import java.util.ArrayList;
import java.util.List;
interface AuctionMediator {
    void registerBidder(Bidder bidder);
    void placeBid(Bidder bidder, double bidAmount);
}

class AuctionHouse implements AuctionMediator {
    private final List<Bidder> bidders = new ArrayList<>();

    @Override
    public void registerBidder(Bidder bidder) {
        bidders.add(bidder);
    }

    @Override
    public void placeBid(Bidder bidder, double bidAmount) {
        System.out.println(bidder.getName() + " placed a bid of $" + bidAmount);
        // Notify other bidders about the new bid
        for (Bidder b : bidders) {
            if (b != bidder) {
                b.notifyBid(bidder, bidAmount);
            }
        }
    }
    
}

class Bidder {
    private String name;
    private AuctionMediator mediator;

    public Bidder(String name, AuctionMediator mediator) {
        this.name = name;
        this.mediator = mediator;
        mediator.registerBidder(this);
    }

    public String getName() {
        return name;
    }

    public void placeBid(double bidAmount) {
        mediator.placeBid(this, bidAmount);
    }

    public void notifyBid(Bidder bidder, double bidAmount) {
        System.out.println(name + " is notified that " + bidder.getName() + " placed a bid of $" + bidAmount);
    }
}

public class MediatorMain {
    public static void main(String[] args) {
        AuctionMediator auctionHouse = new AuctionHouse();

        Bidder bidder1 = new Bidder("Alice", auctionHouse);
        Bidder bidder2 = new Bidder("Bob", auctionHouse);
        Bidder bidder3 = new Bidder("Charlie", auctionHouse);

        bidder1.placeBid(100);
        bidder2.placeBid(150);
        bidder3.placeBid(200);
    }
}