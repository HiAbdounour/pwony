/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Etudiant{
    //Etudiant(string e,string g,vector<float> n) : nomEtu(n), groupe(g), notes(n) {}
    
    string nomEtu;
    string groupe;
    vector<float> notes;
};

bool is_in_vector(vector<Etudiant> liste_etu, string nom, int &index){
    for(int i=0;i<liste_etu.size();i++){
        if(liste_etu.at(i).nomEtu==nom){
            index=i;
            return true;
            
        }
    }
    return false;
}

void fusion_fichier_notes(vector<string> filenames,string finalfilename){
    vector<Etudiant> liste = {};
    
    for(int i=0;i<filenames.size();i++){
        ifstream file;
        file.open(filenames.at(i));
        if(!file){
            cout << filenames.at(i) << " not found !"<<endl;
            continue;
        }
        
        string nomX,grpX; float noteX;
        while(file>>nomX && file>>grpX && file>>noteX){
            int index;
            if(!is_in_vector(liste,nomX,index)){
                Etudiant etu;
                etu.nomEtu = nomX; etu.groupe = grpX;
                vector<float> x(i,0.f); x.push_back(noteX);
                etu.notes = x;
                liste.push_back(etu);
            }
            else{
                liste.at(index).notes.push_back(noteX);
            }
        }
        
        file.close();
    }
    
    ofstream finalfile;
    finalfile.open(finalfilename); //does exist (?)
    for(auto etu:liste){
        finalfile << etu.nomEtu << ' ' << etu.groupe;
        for(auto note:etu.notes){
            finalfile << ' ' << note;
        }
        finalfile << endl;
    }
    finalfile.close();
}



int main(){
    
    return 0;
}
