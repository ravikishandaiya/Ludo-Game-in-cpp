#include <iostream>
#include<fstream>

#ifdef __linux__
	#include <unistd.h>	//For usleep()
#else
	#include <windows.h>	//For Sleep()
#endif

void pauseFunction(int milliSec){
	#ifdef __linux__
		usleep(1000*milliSec);
	#else
		Sleep(milliSec);
	#endif
}
void clearFunction(){
	#ifdef __linux__
		system("clear");
	#else
		system("cls");
	#endif
}

using namespace std;
int countp1=0,countp2=0;
class game {
	public:
		int pl1[4],pl2[4]; //variables of players coin 
		char p1[20],p2[20];
		game() {
			for(int i=0; i<4; i++) {
				pl1[i]=-1;
				pl2[i]=-2;
			}
		}
	void input_data() {
		cout<<"Enter First player name:";
		cin>>p1;
		cout<<"Enter Second player name:";
		cin>>p2;
	}




	void display() {
	}	
	
	
	
	
void logic_fun_p1() {
		srand(time(0));
		int count=2,x;
		while(count>=2) {
			count--;
		x=(rand()%6+1);
	
		int count1=0;
		cout<<endl<<p1<<", its your turn(press ENTER to throw dice)-";
		cin.get();
		cout<<"\nWait Please..";
		pauseFunction(500);
		cout<<endl<<"you got '"<<x<<"' on dice"<<endl;
		cout<<"\nCurrent location of your coins:\n";
		cout<<pl1[0]<<endl<<pl1[1]<<endl<<pl1[2]<<endl<<pl1[3]<<endl;
			if(x==1 || x==6)
			countp1++;
		if(countp1==0){
			cout<<"\nYou didn't get 1 or 6, you do not have any choice ";
		}
		else {
		cout<<"\nwhich coin you want to play:";
		int guti,w=0;
		while(w==0){
			w=0;
			cin>>guti;
			guti-=1;
			
			
			if(pl1[guti]>=101 && pl1[guti]<106) {
				int temp=pl1[guti];
				if(temp+x<=106) {
					pl1[guti]+=x;
					w=1;
				}
				else {
					cout<<"\nOops ! \nYou choose wrong Coin, please try again (bcz it haven't more):";
					cout<<"\nIf you do not have no more choice press '1'";
					int tempo;
					cin>>tempo;
					if(tempo!=1){
						w=0;
						cout<<"\nEnter coin number:";
					}
				}
				
			}			
			
			if(pl1[guti]>=0 && pl1[guti]<51) {

				int temp=pl1[guti];
				if(temp+x<51){
				
				pl1[guti]+=x;
				w=1;	
				}
				else {
					int temp1=pl1[guti]+x;
					temp1-=50;
					pl1[guti]=100+temp1;
					w=1;
					}			

			}
			if(pl1[guti]==-1) {
				if(x==6 || x==1)
					{
						pl1[guti]=0;
						w=1;
				
					}
				else {
					cout<<"\nOops ! \n This coin can not start,try again:";
					cout<<"\nif you want to choose another coin press '1'\n(if you do not have any choice press 0 )  ";
					int tempo;
					cin>>tempo;
					if(tempo==1)
					w=0;
					else
					w=1;
				}
			}
			
			if(pl1[guti]==106) {
				cout<<"You Are Done With This Coin, Its Is At Destination try againwith another coin:";
			
			}

		} 	
			
		if(pl1[guti]!=0 || pl1[guti]!=8 || pl1[guti]!=13 || pl1[guti]!=21 || pl1[guti]!=26 || pl1[guti]!=34 || pl1[guti]!=39 || pl1[guti]!=47)
		 {
			if(pl1[guti]==pl2[0]) {
				pl2[0]=-2;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 2:"<<p2<<"Your coin has captured";
			}
			if(pl1[guti]==pl2[1]) {
				pl2[1]=-2;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 2:"<<p2<<"Your coin has captured";
			}
			if(pl1[guti]==pl2[2]) {
				pl2[2]=-2;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 2:"<<p2<<" Your coin has captured";
			}
			if(pl1[guti]==pl2[3]) {
				pl2[3]=-2;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 2:"<<p2<<" Your coin has captured";
			}
		}
		
	if(count1>0) {
		count++;
	}
	}
}
}


	
void logic_fun_p2() {
		int count=2,x;
		srand(time(0));
		while(count>=2) {
			count--;
		x=(rand()%6)+1;	
		int count1=0;
		int guti,w=0;
		cout<<endl<<p2<<", its your turn(press ENTER to throw dice)-";
		cin.get();
		cout<<"\nWait Please..";
		pauseFunction(500);
		cout<<endl<<"you got '"<<x<<"' on dice"<<endl;
		cout<<"\nCurrent location of your coins:\n";
		cout<<pl2[0]<<endl<<pl2[1]<<endl<<pl2[2]<<endl<<pl2[3]<<endl;
			if(x==1 || x==6)
			countp2++;
		if(countp2==0){
			cout<<"\nYou didn't get 1 or 6, you do not have any choice ";
		}
		else
		{
		
		while(w==0){
			w=0;
			cout<<"\nwhich one coin to want to play:";
			cin>>guti;
			guti-=1;
			
			if(pl2[guti]>=201 && pl2[guti]<206) {
				int temp=pl2[guti];
				if(temp+x<=206) {
					pl2[guti]+=x;
					w=1;
				}
				else {
					cout<<"Oops ! \nYou choose wrong Coin, please try again (bcz it haven't more steps):";
					cout<<"\nIf you do not have no more choice press '1' else 0 or anything ";
				}
				
					int tempo;
					cin>>tempo;
					if(tempo==1){
						w=1;
					}
				
			}			
			
			if(pl2[guti]>=0 && pl2[guti]<25) {
				int temp=pl2[guti] + x;
				if(temp<25) {
					pl2[guti]+=x;
					w=1;
				}
				else {
					temp=temp-24;
					pl2[guti]=200+temp;
					w=1;
				}
			}
			
			if(pl2[guti]>=26 && pl2[guti]<=51) 
			{
				int temp=pl2[guti];
				if(temp+x<=51){
				
				pl2[guti]+=x;
				w=1;
			}
				else {
					int temp1=pl2[guti]+x;
					temp1-=52;
					pl2[guti]=0+temp1;
					w=1;
					}			

			}
			if(pl2[guti]==-2) {
				if(x==6 || x==1)
					{
						pl2[guti]=26;
						w=1;
		
					}
				else {
					w=1;
					cout<<"\nOops ! \nThis coin can not start, try again:";
					cout<<"\nif you want to choose another coin press '1'\n(if you do not have any choice press 0 ) ";
					int tempo;
					cin>>tempo;
					if(tempo==1)
					{
						cout<<"\nEnter coin number:";
						w=0;
					}
					else
					w=1;
				}
			}
			if(pl2[guti]==206) {
				cout<<"You Are Done With This Coin, It Is At Destination try again with another coin:";
			}

			
				
				
						
		}
		if(pl2[guti]!=0 || pl2[guti]!=8 || pl2[guti]!=13 || pl2[guti]!=21 || pl2[guti]!=26 || pl2[guti]!=34 || pl2[guti]!=39 || pl2[guti]!=47)
		 {
			if(pl2[guti]==pl1[0]) {
				cout<<endl<<"Oops ! \n PLAYER 1:"<<p1<<" Your coin has captured";
				pl1[0]=-1;
				count1++;
			}
			if(pl2[guti]==pl1[1]) {
				pl1[1]=-1;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 1:"<<p1<<" Your coin has captured";
			}
			if(pl2[guti]==pl1[2]) {
				pl1[2]=-1;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 1:"<<p1<<" Your coin has captured";
			}
			if(pl2[guti]==pl1[3]) {
				pl1[3]=-1;
				count1++;
				cout<<endl<<"Oops ! \n PLAYER 1:"<<p1<<" Your coin has captured";
			}
		} 
			
	if(count1>0) {
		count=2;
	}
	}
}
}

	


};


int main() {
	int x;
	game obj;
	string s="START GAME";
	for(int a=0; a<22; a++ ){
		for(int b=0; b<82; b++){
			if(a==0 || b==0 || a==21 || b==81)
				cout<<"*";
			else if(a==10 && b>35 && b<46)
				cout<<s[b-36];
			else
				cout<<" ";
		}
		cout<<endl;
	} 
	pauseFunction(500);
	clearFunction();
	
	for(int k=0; k<5; k++){
		cout<<"#";
		pauseFunction(100);
	}
	pauseFunction(500);
	clearFunction();
	char temp[20];
	obj.input_data();
	while((obj.pl1[0]!=106 && obj.pl1[1]!=106 && obj.pl1[2]!=106 && obj.pl1[3]!=106) || (obj.pl2[0]!=206 && obj.pl2[1]!=206 && obj.pl2[2]!=206 && obj.pl2[3]!=206))
	 {
		obj.logic_fun_p1();
		cout<<"\nUpdated location of coins for player1: "<<obj.p1<<endl;
		cout<<obj.pl1[0]<<endl<<obj.pl1[1]<<endl<<obj.pl1[2]<<endl<<obj.pl1[3]<<endl;
		cout<<"\n(clear)";
		cin.get();
		clearFunction();		
		obj.logic_fun_p2();
		cout<<"\nUpdated location of coins for player2: "<<obj.p2<<endl;
		cout<<obj.pl2[0]<<endl<<obj.pl2[1]<<endl<<obj.pl2[2]<<endl<<obj.pl2[3]<<endl;
		cout<<"\n(clear)";
		cin.get();
		clearFunction();		
	}
	if(obj.pl1[0]==106 && obj.pl1[1]==106 && obj.pl1[2]==106 && obj.pl1[3]==106) {
		cout<<"\nPlayer1:"<<obj.p1<<" won";
		ofstream fout;
		fout.open("data.txt", ios::app);
		fout<<obj.p1;
		fout.close();
	}
	if(obj.pl2[0]==206 && obj.pl2[1]==206 && obj.pl2[2]==206 && obj.pl2[3]==206){
		cout<<"\nPlayer2:"<<obj.p2<<" won";
		ofstream fout;
		fout.open("data.txt", ios::app);
		fout<<obj.p2;
		fout.close();
	}
	clearFunction();		
}
