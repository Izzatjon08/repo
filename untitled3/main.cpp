#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string wayT = "temperature.txt";
string wayH = "humidity.txt";
string wayR = "rainfall.txt";
string temp = "temp.txt";
class CityTemp{
public:
    int cityID;
    double data[12] ;
    void setClimatDate(double data[]){
        for (int i =0; i<12;i++)
            this->data[i]=data[i];
    }
    double* getClimatData(){
        return data;
    }
    int getID(){
        return cityID;
    }
    void setID(int i){
        cityID=i;
    }
    void readFromFile(string way){
        ifstream out(way);
        string reader="";
        while (reader!=to_string(cityID)+"_t")
            out>>reader;
        for (int i =0; i< 12;i++)
        {
            out>>reader;
            data[i]=(double)atof(reader.c_str());
        }

    }
    void writeToFile(){
        ofstream file;
                file.open(wayT, std::ios::app);
                file << to_string(cityID)+"_t"<<"\n";
                for (int i =0; i<12; i++)
                {
                    file<<data[i]<<"\n";
                }
                file.close();
    }

    void deletefromFile(){
        ifstream reader(wayT);
        ofstream tmp;
        string read = "";
        tmp.open(temp, std::ios::app);
        while (read!=to_string(cityID)+"_t")
        {
            reader>>read;
            tmp<<read;
        }
        for (int i =0; i< 13;i++)
        {
            string devnull;
            reader>>devnull;
        }
        reader.close();
        tmp.close();
        ofstream file;
                file.open(wayT, std::ios::trunc);
        ifstream readft(temp);
        while (!readft.eof()) {
            string buffer;
            readft>>buffer;
            file<<buffer;
        }
        file.close();
        readft.close();
    }

    double getAver(){
        int coll = 0;
        for (int i =0; i< 12; i++)
            coll+=data[i];
        return coll/12;
    }
};
class CityRain{
public:
    int cityID;
    double data[12] ;
    void setClimatDate(double data[]){
        for (int i =0; i<12;i++)
            this->data[i]=data[i];
    }
    double* getClimatData(){
        return data;
    }

    int getID(){
        return cityID;
    }
    void setID(int i){
        cityID=i;
    }
    void readFromFile(){
        ifstream out(wayR);
        string reader="";
        while (reader!=to_string(cityID)+"_r")
            out>>reader;
        for (int i =0; i< 12;i++)
        {
            out>>reader;
            data[i]=(double)atof(reader.c_str());
        }

    }
    void writeToFile(){
        ofstream file;
                file.open(wayR, std::ios::app);
                file << to_string(cityID)+"_r"<<"\n";
                for (int i =0; i<12; i++)
                {
                    file<<data[i]<<"\n";
                }
                file.close();
    }

    void deletefromFile(){
        ifstream reader(wayR);
        ofstream tmp;
        string read = "";
        tmp.open(temp, std::ios::app);
        while (read!=to_string(cityID)+"_r")
        {
            reader>>read;
            tmp<<read;
        }
        for (int i =0; i< 13;i++)
        {
            string devnull;
            reader>>devnull;
        }
        reader.close();
        tmp.close();
        ofstream file;
                file.open(wayR, std::ios::trunc);
        ifstream readft(temp);
        while (!readft.eof()) {
            string buffer;
            readft>>buffer;
            file<<buffer;
        }
        file.close();
        readft.close();
    }

    double getAver(){
        int coll = 0;
        for (int i =0; i< 12; i++)
            coll+=data[i];
        return coll/12;
    }

};
class CityHum{
public:
    int cityID;
    double data[12] ;
    void setClimatDate(double data[]){
        for (int i =0; i<12;i++)
            this->data[i]=data[i];
    }
    double* getClimatData(){
        return data;
    }

    int getID(){
        return cityID;
    }
    void setID(int i){
        cityID=i;
    }
    void readFromFile(){
        ifstream out(wayH);
        string reader="";
        while (reader!=to_string(cityID)+"_h")
            out>>reader;
        for (int i =0; i< 12;i++)
        {
            out>>reader;
            data[i]=(double)atof(reader.c_str());
        }

    }
    void writeToFile(){
        ofstream file;
                file.open(wayH, std::ios::app);
                file << to_string(cityID)+"_h"<<"\n";
                for (int i =0; i<12; i++)
                {
                    file<<data[i]<<"\n";
                }
                file.close();
    }
    void deletefromFile(){
        ifstream reader(wayH);
        ofstream tmp;
        string read = "";
        tmp.open(temp, std::ios::app);
        while (read!=to_string(cityID)+"_h")
        {
            reader>>read;
            tmp<<read;
        }
        for (int i =0; i< 13;i++)
        {
            string devnull;
            reader>>devnull;
        }
        reader.close();
        tmp.close();
        ofstream file;
                file.open(wayH, std::ios::trunc);
        ifstream readft(temp);
        while (!readft.eof()) {
            string buffer;
            readft>>buffer;
            file<<buffer;
        }
        file.close();
        readft.close();
    }
    double getAver(){
        int coll = 0;
        for (int i =0; i< 12; i++)
            coll+=data[i];
        return coll/12;
    }
};


class City{
public:
    int ID;
    CityHum ch;
    CityRain cr;
    CityTemp ct;
    string cityName;
    string getcityName(){
        return this->cityName;
    };
    void setCityName(string n)
    {
        cityName = n;
    }
    int getID(){
        return ID;
    }
    void setID(int i){
        ID=i;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
