/*
     Nama      : Risyad pangestu
     NPM       : 140810170003
     Kelas     : A
     Tanggal   : 05 Maret 2019
     PROGRAM STABLE MATCHING 
*/

#include <iostream>
using namespace std;
 
typedef int prefer[5];
 
struct people{
     string name;
     int pasangan;
     int preferences[5];
};
 
people setDatapeople(string name, prefer prefers);
void stableMatching(people man[5], people women[5]);
 
int main(){
     people man[5], women[5];
     prefer prefers;
 
     //man
	prefers[0] = 1; prefers[1] = 0; prefers[2] = 3; prefers[3] = 4; prefers[4] = 2;
	man[0] = setDatapeople("Victor",prefers);
	prefers[0] = 3; prefers[1] = 1; prefers[2] = 0; prefers[3] = 2; prefers[4] = 4;
	man[1] = setDatapeople("Wyatt",prefers);
	prefers[0] = 1; prefers[1] = 4; prefers[2] = 2; prefers[3] = 3; prefers[4] = 0;
	man[2] = setDatapeople("Xavier",prefers);
	prefers[0] = 0; prefers[1] = 3; prefers[2] = 2; prefers[3] = 1; prefers[4] = 4;
	man[3] = setDatapeople("Yancey",prefers);
	prefers[0] = 1; prefers[1] = 3; prefers[2] = 0; prefers[3] = 4; prefers[4] = 2;
	man[4] = setDatapeople("Zeus",prefers);
 
	//women
	prefers[0] = 4; prefers[1] = 0; prefers[2] = 1; prefers[3] = 3; prefers[4] = 2;
	women[0] = setDatapeople("Amy",prefers);
	prefers[0] = 2; prefers[1] = 1; prefers[2] = 3; prefers[3] = 0; prefers[4] = 4;
	women[1] = setDatapeople("Bertha",prefers);
	prefers[0] = 1; prefers[1] = 2; prefers[2] = 3; prefers[3] = 4; prefers[4] = 0;
	women[2] = setDatapeople("Clare",prefers);
	prefers[0] = 0; prefers[1] = 4; prefers[2] = 3; prefers[3] = 2; prefers[4] = 1;
	women[3] = setDatapeople("Diane",prefers);
	prefers[0] = 3; prefers[1] = 1; prefers[2] = 4; prefers[3] = 2; prefers[4] = 0;
	women[4] = setDatapeople("Erika",prefers);
 
     stableMatching(man,women);
 
     cout << "\nHasil Stable Matching :" << endl;
     cout << "-----------------" << endl
          << "| Man \t Woman\t|" << endl
          << "-----------------" << endl;
     for(int i = 0; i < 5; i++){
          cout << "|" << man[i].name << "\t " << women[man[i].pasangan].name << "\t|" << endl;
     }
     cout << "-----------------" << endl;
}
 
people setDatapeople(string name, prefer prefers){
     people org;
     org.name = name;
     org.pasangan = -1;
     for(int i = 0; i < 5;i++){
          org.preferences[i] = prefers[i];
     }
     return org;
}
 
void stableMatching(people man[5], people women[5]){
     bool bebas = true;
     int i=0, j=0, prefSek,prefSuk;
     while(bebas){
          if(women[man[i].preferences[j]].pasangan = -1){
               man[i].pasangan = man[i].preferences[j];
               women[man[i].preferences[j]].pasangan = i;
          }else{
			int k = 0;
			prefSek = -1; prefSuk = -1;
			while(prefSek == -1 || prefSuk == -1){
				if(i == women[man[i].preferences[j]].preferences[k]){
					prefSuk = k;
				}
				if(women[man[i].preferences[j]].pasangan == women[man[i].preferences[j]].preferences[k]){
					prefSek = k;
				}
				k++;
			}
			if(prefSuk<prefSek){
				man[women[man[i].preferences[j]].pasangan].pasangan = -1;
				man[i].pasangan = man[i].preferences[j];
				women[man[i].preferences[j]].pasangan = i;
			}else{
				j++;
				continue;
			}
		}
		bebas = false;
		j=0;
		for(int l = 0; l < 5; l++){
			if(man[l].pasangan == -1){
				i = l;
				bebas = true;
				break;
			}
		}
     }
}
