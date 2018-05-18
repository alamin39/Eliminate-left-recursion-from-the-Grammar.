/// Program to eliminate left recursion from the Grammar.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char non_terminal,beta,root;
    int x=1, num, i, j, option, index, A_index=0, B_index=0, A_t=0, B_t=0;

    cout<<"\t\t*** WELCOME TO OUR PROJECT! ***\n\n";
    cout<<"1: Single Grammar.\n";
    cout<<"2: Two Grammar which can Replace.\n";
    cout<<"Choose an option: ";
    cin>>option;
    cout<<"\n";

    num=option;
    string production[num+1],alpha,temp;
    string A[401], B[401], match[201][105], A_terminal[401], B_terminal[401];
    map<char,bool>mm;


            /// *** Input part ****
    cout<<"\nEnter Valid Grammar like as E->E+A|b :\n";
    for(i=0; i<num; i++)
    {
        cin>>production[i];
        temp="";
        production[i]+="|";
        if(i==0) //for root
        {
            for(j=3; j<production[i].size(); j++)
            {
                if(production[i][j]=='|')
                {
                    if(production[i][0]==temp[0])
                    {
                        A[A_index++]=temp;
                    }
                    else
                    {
                        B[B_index++]=temp;
                    }
                    temp="";
                }
                else
                    temp+=production[i][j];
            }
        }
        else
        {
            mm[production[i][0]]=x;
            temp="";
            int l=0;
            for(j=3; j<production[i].size(); j++)
            {
                if(production[i][j]=='|')
                {
                    match[x][l++]=temp;
                    temp="";
                }
                else
                    temp+=production[i][j];
            }
            match[x][l]="";
            x++;
        }
    }


        /// *** Matching part ****

    string prev="",next="";
    for(i=0; i<A_index; i++)
    {
        prev=next="";
        bool f=0;
        for(j=0; j<A[i].size(); j++)
        {
            if(mm[A[i][j]])
            {
                next="";
                for(int l =j+1; l<A[i].size(); l++)
                {
                    next+=A[i][l];
                }
                for(int k=0; match[mm[A[i][j]]][k].size()!=0; k++)
                {
                    A_terminal[A_t]=prev;
                    A_terminal[A_t]+=match[mm[A[i][j]]][k];
                    A_terminal[A_t]+=next;
                    A_t++;
                    f=1;
                }
            }
            else
                prev+=A[i][j];
        }
        if(!f)
        {
            A_terminal[A_t]=prev;
            A_t++;
        }
    }

    prev="",next="";
    for(i=0; i<B_index; i++)
    {
        prev=next="";
        bool f=0;
        for(j=0; j<B[i].size(); j++)
        {
            if(mm[B[i][j]])
            {
                next="";
                for(int l =j+1; l<B[i].size(); l++)
                {
                    next+=B[i][l];
                }
                for(int k=0; match[mm[B[i][j]]][k].size()!=0; k++)
                {
                    B_terminal[B_t]=prev;
                    B_terminal[B_t]+=match[mm[B[i][j]]][k];
                    B_terminal[B_t]+=next;
                    B_t++;
                    f=1;
                }
            }
            else
                prev+=B[i][j];
        }
        if(!f)
        {
            B_terminal[B_t]=prev;
            B_t++;
        }
    }

            /// Printing part. ///
/// ****this part shows After replace Actual grammar****

    root = production[0][0];

    if(num==2)
    {
        cout<<"\nAfter Replace Actual Grammar is:\n\n";
        cout<<root<<"->"<<A_terminal[0];
        for(i=1; i<A_t; i++)
        {
            cout<<"|"<<A_terminal[i];
        }
        for(i=0; i<B_t; i++)
        {
            cout<<"|"<<B_terminal[i];
        }
        cout<<"\n\n";
    }

/// *** this part shows Grammar after eleminating left recursion ****

    cout<<"\nGrammar After Eleminate Left Recursion:\n\n";
    cout<<root<<"->"<<B_terminal[0]<<root<<"'";
    for(i=1; i<B_t; i++)
    {
        cout<<"|"<<B_terminal[i]<<root<<"'";
    }

    cout<<"\n\n"<<root<<"'->";
    for(i=0; i<A_t; i++)
    {
        for(j=1; j<A_terminal[i].size(); j++)
            cout<<A_terminal[i][j];
        cout<<root<<"'|";
    }
    cout<<"@\n\n";
    cout<<"\t\t *** THANK YOU!! ***\n";

        /// **** THE END! ****

    return 0;
}
