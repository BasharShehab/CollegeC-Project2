#include <iostream>
using namespace std;

// converting a number from decimal to binary. 
void dectobin(int n){
	//saving the remainder in an array and printing them out the opposite way.
	int a[32], i, save = n, counter = 0;
	if (n != 0) {
		for (i = 0; n > 0; i++){
			a[i] = n % 2;
			n = n / 2;
			counter++;
		}
		cout << "The number " << save << " in binary is :  ";
		for (i = counter - 1; i >= 0; i--)
			cout << a[i];
		cout << endl;
	}
	else
		cout << "The number 0 in binary is : 0 " << endl;
}
// determining if a year is a leap year or not. 
bool leap_year(int y) {
	if ((y % 4 == 0) && (y % 100 == 0) && (y % 400 == 0))
		return true;

	else if ((y % 4 == 0) && (y % 100 > 0))
		return true;

	return false;
}
// determining if the number is a paindromic number or not. 
void palindrome(int pal) {
	int ans = 0;
	int save = pal;
	while (pal > 0){
		ans = ans * 10 + (pal % 10);
		pal = pal / 10;
	}

	if (ans == save)
		cout << "The number " << ans << " is a palindromic number " << endl;

	else
		cout << "The number " << save << " is not a palindromic number " << endl;
}
int main() {
	int choice, year;
	float x;
	int palchk;
	cout << " Enter 1 to enter the Decimal to Binary program" << endl;
	cout << " Enter 2 to enter the Leap Year program " << endl;
	cout << " Enter 3 to enter the Palindrome program " << endl;
	cin >> choice;
	// i came up with a way to do something like a telephone auto dialog. 
	while ( choice > 3 || choice < 1 ) {
			cout << "Please enter only 1, 2, or 3 " << endl;
			cin.clear();
			cin >> choice;
	}
	// if choice is 1 you enter the decimal to binary program.
	if (choice == 1) {
		cout << "Enter the decimal number : " << endl;
		cin >> x;
		while (x >= 9999999999 || x < 0) {
			cout << "Please enter a positive number lower than 10 digits. " << endl;
			cin.clear();
			cin >> x;
		}
		dectobin(x);
	}


	// if choice is 2 you enter the leap year check. 
	else if (choice == 2) {
		cout << " Enter the year to check if its a leap year : " << endl;
		cin >> year;
		while (year >= 9999999999 || year < 0) {
			cout << "Please enter a valid year " << endl;
			cin.clear();
			cin >> year;
			cout << endl;
		}

		if (leap_year(year) == true)
			cout << "The year " << year << " is a leap year " << endl;

		else
			cout << "The year " << year << " is not a leap year " << endl;
	}

	// if choice is 3 you enter the palindromic number check. 
	else if (choice == 3) {
		cout << "Enter a number to check if its a palindromic number or not : " << endl;
		cin >> palchk;
		while (palchk < 0 || palchk > 2147483646 ){
			cout << "Please enter a valid number. \nNegative numbers or numbers larger than 9 digits are not allowed. " << endl;
			cin.clear();
			cin >> palchk;
		}
		palindrome(palchk);
	}
	return 0;
}
