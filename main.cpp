#include <iostream>
using namespace std;

int inputNumberFromConsole(int MinVal, int MaxVal, string AskMsg, string ErrorMsg) {
	int NumberForCheck;
	cout << AskMsg;
	do {
		cin >> NumberForCheck;
		if (cin.peek() != '\n' || MinVal > NumberForCheck || MaxVal < NumberForCheck) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << ErrorMsg;
		}
	} while (cin.peek() != '\n' || MinVal > NumberForCheck || MaxVal < NumberForCheck);
	return NumberForCheck;
}

int Method(){

  short int Condition = rand()%3-0;
  bool *Case = new bool[3];

  for(short int i=0;i<3;i++)
    Case[i]=0;
  Case[Condition]=1;

  bool win1 = 0;
  bool win2 = 0;
  short int box = rand()%3-0;
  bool choose=rand()%2-0;

  if(!choose&&Case[box])
    win2=true;
  else if (choose&&!Case[box])
    win1=true;
  
  if (win1)
    return 1;
  else if (win2)
    return 2;
  else
    return 3;
}

int main() {
  srand(time(0));
  cout<<"Check Monty Hall problem.\nRandom Generation of 1kk cases.\n";
  short int Simulation = inputNumberFromConsole(1, 15, "Input number of simulations: ", "please, input number from 1 to 15: ");
  cout << "Hall Method           ";
  cout << "Amateur              ";
  cout << "Casino     \n";
  for(short int i=0; i<Simulation; i++){
  float won1=0;
  float won2=0;
  float won3=0;
  short int result = 0;
  for(int i=0;i<1000000;i++)
  {
    result = Method();
    if(result == 1)
      won1++;
    else if(result == 2)
      won2++;
    else
      won3++;
  }
  string tab = to_string(won1/10000) + '%';
  string tab2 = to_string(won2/10000) + '%';
  string tab3 = to_string(won3/10000) + '%';
  cout.width(22);
  cout << left << tab;
  cout.width(21);
  cout << left << tab2;
  cout << left << tab3 << endl;
  }
}
