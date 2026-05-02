// class LeaveRequestTraditional {
//     public static void main(String[] args) {
//         String employee = "John";
//         int leaveDays = 5;

//         if (leaveDays <= 2) {
//             System.out.println("Leave approved by Team Lead for " + employee);
//         } else if (leaveDays <= 5) {
//             System.out.println("Leave approved by Manager for " + employee);
//         } else {
//             System.out.println("Leave approved by HR for " + employee);
//         }
//     }
// }

// Approver is an abstract class instead of an interface because it needs to share
// state (nextApprover field) and behavior (setNextApprover method) among all concrete
// approvers, which interfaces cannot provide in Java. This allows us to avoid code
// duplication and maintain a common structure for the chain of responsibility.
abstract class Approver {
    protected Approver nextApprover;

    public void setNextApprover(Approver nextApprover) {
        this.nextApprover = nextApprover;
    }

    public abstract void approveLeave(String employee, int leaveDays);
}

class TeamLead extends Approver {
    @Override
    public void approveLeave(String employee, int leaveDays) {
        if (leaveDays <= 2) {
            System.out.println("Leave approved by Team Lead for " + employee);
        } else if (nextApprover != null) {
            nextApprover.approveLeave(employee, leaveDays);
        }
    }
}

class Manager extends Approver {
    @Override
    public void approveLeave(String employee, int leaveDays) {
        if (leaveDays <= 5) {
            System.out.println("Leave approved by Manager for " + employee);
        } else if (nextApprover != null) {
            nextApprover.approveLeave(employee, leaveDays);
        }
    }
}

class HR extends Approver {
    @Override
    public void approveLeave(String employee, int leaveDays) {
        System.out.println("Leave approved by HR for " + employee);
    }
}


public class ChainofResponsibility {
    public static void main(String[] args) {
        Approver teamLead = new TeamLead();
        Approver manager = new Manager();
        Approver hr = new HR();

        teamLead.setNextApprover(manager);
        manager.setNextApprover(hr);

        String employee = "John";
        int leaveDays = 5;

        teamLead.approveLeave(employee, leaveDays);
    }
}
