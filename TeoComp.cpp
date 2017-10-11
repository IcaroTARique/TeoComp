//clang++ -std=c++0x TeoComp.cpp -o TeoComp.o

#include <iostream>
#include <regex>
#include <string>
#include <ctype.h>
#include <string.h>

using namespace std;

//FUNÇÃO QUE COMPARA A RESPOSTA **********************************
int compara (string palavra){

    string sim = "SIM";
    int cont = 0;

    for (int i = 0; i < palavra.length() ; ++i)
        {
           if (palavra[i] ==  sim[i]){
                cont++;
           }
         }
        // cout << "CONT = " << cont << endl;
    if (cont == 3){
        cont = 1;
    }else{
        cont =0;
    }
return cont;
}
// MAIN *****************************************************************
int main () {

    string numerocel;
    string numerofixo;
    string cpf;
    string placa;
    string resposta;
    bool condition = false;

        while(true){

            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
                          "##::::::::::'###::::'##::::'##::::'###:::::::::::::::::::'##::::'###::::'########::'#######::\n"
                          "##:::::::::'## ##::: ##:::: ##:::'## ##:::::::::::::::::: ##:::'## ##:::... ##..::'##.... ##:\n"
                          "##::::::::'##:. ##:: ##:::: ##::'##:. ##::::::::::::::::: ##::'##:. ##::::: ##:::: ##:::: ##:\n"
                          "##:::::::'##:::. ##: ##:::: ##:'##:::. ##:'#######::::::: ##:'##:::. ##:::: ##:::: ##:::: ##:\n"
                          "##::::::: #########:. ##:: ##:: #########:........:'##::: ##: #########:::: ##:::: ##:::: ##:\n"
                          "##::::::: ##.... ##::. ## ##::: ##.... ##:::::::::: ##::: ##: ##.... ##:::: ##:::: ##:::: ##:\n"
                          "########: ##:::: ##:::. ###:::: ##:::: ##::::::::::. ######:: ##:::: ##:::: ##::::. #######::\n"
                          "........::..:::::..:::::...:::::..:::::..::::::::::::......:::..:::::..:::::..::::::.......::\n" << endl;




            //Recebe Nome
            cout << "Qual o Numero do CPF do Senhor/Senhora?" << endl;
            cin >> cpf;

            //Recebe Placa do Carro

            cout << "Qual a placa do Carro ?" << endl;
            cin >> placa;

            //Recebe resposta SIM ou NÃO
            cout << "Tem Numero de telefone fixo - sim | nao - ?? " << endl;
            cin >> resposta;

            //CONVERTE RESPOSTA PARA MAIUSCULO
            for (int i = 0; i < resposta.length() ; ++i){
                    resposta[i] = toupper(resposta[i]);
                }

            // COMPARA A RESPOSTA CHAMANDO A FUNÇÃO E PEGA O NUMERO FIXO
            if (compara(resposta)){
                cout << "Digite um numero de telefone fixo no formato (XX)xxxx-xxxx " << endl;
                cin >> numerofixo;
            }

            //Recebe resposta SIM ou NÃO
            cout << "Tem Numero de telefone celular - sim | nao - ?? " << endl;
            cin >> resposta;

            //CONVERTE A RESPOSTA PARA MAIUSCULO
            for (int i = 0; i < resposta.length() ; ++i){
              resposta[i] = toupper(resposta[i]);
            }

            // COMPARA A RESPOSTA CHAMANDO A FUNÇÃO E PEGA O NUMERO DE CELULAR
            if(compara(resposta)){
                cout << "Digite, então, um numero de celular no formato (XX)xxxxx-xxxx " << endl;
                cin >> numerocel;
            }
            //regex pattelunificado("\\([0-9]{2}\\)[0-9]{4,5}-[0-9]{4}");
            regex patcpf("[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}-[0-9]{2}");
            regex patplaca("[a-zA-z]{3}-[0-9]{4}", regex_constants::icase);
            regex patcel("\\([0-9]{2}\\)[0-9]{5}-[0-9]{4}");
            regex patfixo("\\([0-9]{2}\\)[0-9]{4}-[0-9]{4}");


            bool matchcpf = regex_match(cpf, patcpf);
            bool matchplaca = regex_match(placa, patplaca);
            bool matchfixo = regex_match(numerofixo, patfixo);
            bool matchcel = regex_match(numerocel, patcel);

            cout << "*********************************************************************" <<endl;
            cout << ((matchcpf) ? "    PADRÃO DE CPF ACEITO" : "    PADRÃO DE CPF REJEITADO") << endl;
            cout << ((matchplaca) ? "    PADRÃO DE PLACA ACEITO" : "    PADRÃO DE PLACA REJEITADO") << endl;;
            cout << ((matchfixo) ? "    PADRÃO FIXO ACEITO" : "    PADRÃO FIXO REJEITADO") << endl;
            cout << ((matchcel) ? "    PADRÃO DE CELULAR ACEITO" : "    PADRÃO DE CELULAR REJEITADO") << endl;
            cout << "*********************************************************************" <<endl;
            cout << cpf << endl;
            cout << placa << endl;
            cout << numerofixo << endl;
            cout << numerocel << endl;
            cout << "*********************************************************************" <<endl << endl;

            cout << "Fazer outro cadastro - sim | não - ??" << endl;
            cin >> resposta;

            //CONVERTE A RESPOSTA PARA MAIUSCULO
            for (int i = 0; i < resposta.length() ; ++i){
              resposta[i] = toupper(resposta[i]);
            }

            // COMPARA A RESPOSTA CHAMANDO A FUNÇÃO E PEGA O NUMERO DE CELULAR
            if(!compara(resposta)){
                break;
            }
    }
    return 0;
}
