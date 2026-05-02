interface Patient {
    void accept(Visitor visitor);
}

class childPatient implements Patient {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}

class adultPatient implements Patient {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}

class SeniorPatient implements Patient {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}

interface Visitor {
    void visit(childPatient child);
    void visit(adultPatient adult);
    void visit(SeniorPatient senior);
}

class DiagnosisVisitor implements Visitor {
    @Override
    public void visit(childPatient child) {
        System.out.println("Diagnosing child patient");
    }

    @Override
    public void visit(adultPatient adult) {
        System.out.println("Diagnosing adult patient");
    }

    @Override
    public void visit(SeniorPatient senior) {
        System.out.println("Diagnosing senior patient");
    }
}

class TreatmentVisitor implements Visitor {
    @Override
    public void visit(childPatient child) {
        System.out.println("Treating child patient");
    }

    @Override
    public void visit(adultPatient adult) {
        System.out.println("Treating adult patient");
    }

    @Override
    public void visit(SeniorPatient senior) {
        System.out.println("Treating senior patient");
    }
}

public class VisitorMain {
    public static void main(String[] args) {
        Patient child = new childPatient();
        Patient adult = new adultPatient();
        Patient senior = new SeniorPatient();

        Visitor diagnosisVisitor = new DiagnosisVisitor();
        Visitor treatmentVisitor = new TreatmentVisitor();

        child.accept(diagnosisVisitor);
        adult.accept(diagnosisVisitor);
        senior.accept(diagnosisVisitor);

        child.accept(treatmentVisitor);
        adult.accept(treatmentVisitor);
        senior.accept(treatmentVisitor);
    }
}
