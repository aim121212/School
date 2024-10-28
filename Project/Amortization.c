/*Travel Program

#include <stdio.h>

int main () {

//Output

print (a final summary of the destination and costs with descriptions)

print (the first section will showcase a summary of the trip details like selected transportation, )


return 0;
}
*/

#include <stdio.h>
#include <math.h>

void amortization_schedule(double principal, double annual_rate, int years, int payments_per_year) {
    // Convert annual rate to a monthly rate
    double monthly_rate = annual_rate / 100.0 / payments_per_year;
    // Total number of payments
    int total_payments = years * payments_per_year;
    
    // Calculate monthly payment using the formula for an amortizing loan
    double monthly_payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -total_payments));
    
    printf("Monthly Payment: %.2f\n", monthly_payment);
    printf("Amortization Schedule:\n");
    printf("%-10s %-15s %-20s %-20s %-20s\n", "Month", "Payment", "Principal Payment", "Interest Payment", "Remaining Balance");

    double remaining_balance = principal;

    for (int month = 1; month <= total_payments; ++month) {
        // Interest for the current month
        double interest_payment = remaining_balance * monthly_rate;
        // Principal for the current month
        double principal_payment = monthly_payment - interest_payment;
        // Update remaining balance
        remaining_balance -= principal_payment;

        // Print the details for the current month
        printf("%-10d %-15.2f %-20.2f %-20.2f %-20.2f\n", month, monthly_payment, principal_payment, interest_payment, remaining_balance);
    }
}

int main() {
    double principal;
    double annual_rate;
    int years;

    // Example values
    principal = 25000;  // Principal loan amount
    annual_rate = 5.0;  // Annual interest rate
    years = 5;          // Loan term in years

    amortization_schedule(principal, annual_rate, years, 12);

    return 0;
}
