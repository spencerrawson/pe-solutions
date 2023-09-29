#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string letter = "Eqpitcvwncvkqpu! Vjg Quect Cecfgoa qh Ocike ku vjtknngf vq kphqto aqw vjcv aqw jcxg dggp cfokvvgf vq qwt rtguvkikqwu kpuvkvwvkqp. Aqwt jctf yqtm, vcngpv, cpf rcuukqp hqt ocike jcxg gctpgf aqw c rnceg coqpi vjg pgzv igpgtcvkqp qh vjg yqtnf'u itgcvguv ykbctfu. Kp cffkvkqp vq vjg 8 ycpfu tgswktgf hqt vjg qrgpkpi yggm, yg yqwnf nkmg vq tgokpf aqw vq cnuq dtkpi c ecogn ykvj aqw cu c ocikecn etgcvwtg rgv. Vjku ku c pgy tgswktgogpv hqt cnn uvwfgpvu, cu ecognu ctg mpqyp hqt vjgkt cdknkva vq vtcxgtug gxgp vjg jctujguv qh vgttckpu, ocmkpi vjgo rgthgev eqorcpkqpu hqt cpa aqwpi ykbctf qp vjg iq. Rngcug pqvg vjcv vjg vwkvkqp hgg ku pqy hkzgf cv $50,000 rgt ugoguvgt hqt cnn uvwfgpvu fwg vq kphncvkqp. Vjku kpxguvogpv kp aqwt gfwecvkqp cpf vtckpkpi yknn ugv aqw wr hqt c nkhgvkog qh ocikecn uweeguu. Yg nqqm hqtyctf vq ygneqokpi aqw vq vjg cecfgoa cpf jgnrkpi aqw wpnqem aqwt hwnn rqvgpvkcn. Ygnn fqpg!";
    cout << "Welcome to the Oscar Academy of Magic Caesar Cipher Program!" << endl;
    cout << "Unraveling the secret acceptance decision letter from the Oscar Academy of Magic… " << endl;
    cout << "Using a shift value of 2...\n ...\n Drumroll Please...\n The Acceptance Letter Says: " << endl;
    //Print the acceptance letter!
    for(int i = 0; i < letter.length(); i++)
    {
        char temp = letter[i];
        //lowercase if, then uppercase
        if(temp>96 && temp<123)
        {
            temp -=2;
            if(temp < 97) { temp = temp + 26; }
        }
        else if(temp > 64 && temp < 91)
        {
            temp -= 2;
            if(temp < 65) { temp = temp + 26; }
        }
        cout << temp;
    }
    cout << endl;
    //Encode/Decode
    char repeat = 'y';
    while(repeat == 'y')
    {
        char answer = ' ';
        cout << "Do you want to encrypt of decrypt a message? (e/d)";
        cin >> answer;
        cin.ignore();
        int shift = -201;
        string message = "";
        if(answer == 'e')
        {
            cout << "Enter the message to be encoded: ";
            getline(cin, message);
            while(shift < -200 || shift > 200)
            {
                cout << "Enter the shift value (-200-200): ";
                cin >> shift;
                if(shift < -200 || shift > 200) { cout << "Out of range error" << endl; }
            }
            for(char c: message)
            {
                char output = c+shift;
                if(c>96 && c<123)
                {
                while(output < 97 || output > 122)
                    {
                        if(output < 97) { output = output + 26; }
                        else { output = output - 26; }
                    }
                cout << output;
                }
                else if(c>64 && c <91)
                {
                    while(output < 65 || output > 90)
                    {
                        if(output < 65) { output = output + 26; }
                        else { output = output - 26; }
                    }
                    cout << output;
                }
                else
                {
                    cout << c;
                }
                
            }
        }
        else
        {
            cout << "Enter the message to be decoded: ";
            getline(cin, message);
            while(shift < -200 || shift > 200)
            {
                cout << "Enter the shift value (-200-200): ";
                cin >> shift;
                if(shift < -200 || shift > 200) { cout << "Out of range error" << endl; }
            }
            for(char c: message)
            {
                char output = c-shift;
                if(c>96 && c<123)
                {
                    while(output < 97 || output > 122)
                    {
                        if(output < 97) { output = output + 26; }
                        else { output = output - 26; }
                    }
                    cout << output;
                }
                else if(c>64 && c <91)
                {
                    while(output < 65 || output > 90)
                    {
                        if(output < 65) { output = output + 26; }
                        else { output = output - 26; }
                    }
                    cout << output;
                }
                else
                {
                    cout << c;
                }
                
            }
        }
        cout << "\nWould you like to continue the program? (y/n) : ";
        cin >> repeat;
    }
    return 0;
}