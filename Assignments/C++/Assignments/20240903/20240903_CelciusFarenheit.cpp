#include<iostream>

int main(){
	int celc;
	int faren;

	std::cout << "¼·¾¾¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä" << std::endl;
	std::cin >> celc;

	faren = celc * 1.8 + 32;

	std::cout << "ÀÔ·ÂÇØÁÖ½Å ¼·¾¾¸¦ È­¾¾·Î º¯È¯ÇÏ¸é : " << faren << " ¡ÆF " << std::endl;

}