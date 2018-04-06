/* PROJECT ON YAMUNA SPORTS ACADEMY MANAGEMENT SYSTEM*/
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<process.h>
//**********************************************************
// CLASS NAME : Yamuna
// DETAILS    : IT CONTROLS OVER ALL FUNCTIONING
//                  OF THE YAMUNA
//**********************************************************
class yamuna
{
    int  age;
    char name[20];
    char address[50];
    public:
    void aboutus(void);
    void sports(void);
    void facilities(void);
    void contactus(void);
    void membership(void);
};
class member
{
    char address[50];
    char name[20];
    int age;
    int id;
    public:
    void getdata(void);
    void getdat1(void);
    void putdata(void);
    int getid(void);
};
//**********************************************************
// FUNCTION NAME  : GETDATA
//**********************************************************

void member::getdata()
{
    clrscr();
//DATA OF THE CUSTOMER
    cout<<"\n\tEnter Your name: ";
    gets(name);
    cout<<"\n\tEnter Your age: ";
    cin>>age;
    cout<<"\n\tEnter your address: ";
    cin>>address;
    cout<<"\n\tEnter ID no.(any 3 digit no.): ";
    cin>>id;
/*    cout<<"\n\tMember Monthly(M)/Yearly(Y)/Life(L): ";
    cin>>type; */
}
void member::getdat1()
{
    clrscr();
//DATA OF THE CUSTOMER
    cout<<"\n\tEnter Your name: ";
    gets(name);
    cout<<"\n\tEnter Your age: ";
    cin>>age;
    cout<<"\n\tEnter your address: ";
    cin>>address;
    }
void member::putdata()
{
     cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<address<<endl;
    /* getche();*/
}
int member::getid()
{
    return(id);
}
member m;

void write_file()
{
    ofstream afile("member.dat",ios::binary|ios::app);
    m.getdata();
//COPYING THE RECORD OF THE MEMBER INTO A FILE
    afile.write((char*)&m,sizeof(m));
    afile.close();
}
void read_file()
{
    ifstream bfile("member.dat",ios::binary);
    clrscr();
    cout<<"ID      NAME           AGE     ADDRESS\n\n";
    while(bfile.read((char*)&m,sizeof(m)))
    {
    m.putdata();
    }
    cout<<"press any key to continue";
    getche();
    clrscr();
    bfile.close();
}
void search()
{
    int p=-1;
    int n;
    clrscr();
    ifstream cfile("member.dat",ios::binary);
    cout<<"\n Enter ID of member to be searched: ";
    cin>>n;
    while(cfile.read((char*)&m,sizeof(m)))
    {
if(m.getid()==n)
{
m.putdata();
p++;
}
    }
    if(p==-1)
    {
cout<<"records not found!!!!!!!!!!!!!!!!" ;
    }
    cout<<"Press any key to continue";
    getche();
    cfile.close();
}
void modify()
{
int p=-1,t=0;
int n;
clrscr();
cout<<"\n Enter ID member to be modified: ";
cin>>n;
fstream dfile("member.dat",ios::binary|ios::in|ios::out);
while(dfile.read((char*)&m,sizeof(m)))
{
  t++;
  if(m.getid()==n)
  {
m.getdat1();
dfile.seekp((t-1)*sizeof(m),ios::beg);
dfile.write((char*)&m,sizeof(m));
p++;
  }
      }
      if(p==-1)
      {
cout<<"records not found!!!!!!!!!!!!!!!!" ;
      }
      cout<<"Press any key to continue";
      getche();
      dfile.close();
}
void Delete()
{
    int p=-1;
    int n;
    clrscr();
    ifstream efile("member.dat",ios::binary);
    ofstream ffile("temp.dat",ios::binary);
    cout<<"\n enter ID of member to be deleted: ";
    cin>>n;
    while(efile.read((char*)&m,sizeof(m)))
    {
    if(m.getid()!=n)
      {
      ffile.write((char*)&m,sizeof(m));
      p++;
      }
    }
//DELETING THE RECORD OF THE MEMBER
    if(p==-1)
    {
    cout<<"records not found!!!!!!!!!!!!!!!!" ;
    }
    cout<<"Press any key to continue";
    getche();
    clrscr();
    efile.close();
    ffile.close();
    remove("member.dat");
    rename("temp.dat","member.dat");
    }
void yamuna::aboutus()
{
    clrscr();
    cout<<"\n\t\t      *********************************"
<<"\n\t\t      * ***************************** *"
<<"\n\t\t      * *  YAMUNA SPORTS ACADEMY  * *"
<<"\n\t\t      * ***************************** *"
<<"\n\t\t      *********************************\n"
<<"\n\n\n\n\tYamuna Sports Academy is  one of the most proclaimed academies of"
<<"\n\tEast Delhi.The academy  has not only employed experienced coaches"
<<"\n\twho  have represented their country in one or the other sport but"
<<"\n\talso  has the  privilage of producing many of the famous sporting"
<<"\n\tlegends  who are  currently  representing us  on  national level."
<<"\n\tVirender Sehwag, Gautam Gambhir (cricket),Sunil Chhetri(football)"
<<"\n\tSania Mirza(lawn tennis) are to name a few sportspersons produced"
<<"\n\tby this academy. The academy  not only  provides best instructors"
<<"\n\tbut also the best infrastructure for amateur  players to become a"
<<"\n\tworld-class  players.The academy was founded  by Founder Chairman"
<<"\n\tYash Vardhan(of Vardhan Textiles) in the year 1993 as he realized"
<<"\n\tthe importance of a sports institution in the area.\n"
<<"\n\n\n\tThe academy gives coaching for the following sports:-cricket,foot"
<<"\n\tball,basketball,lawn tennis, swimming, atheletics.The academy has";
getche();
cout<<"\n\tfinest coaches,world class stadiums,pools,tracks,courts for every"
<<"\n\tsports.The academy also has facilities for parking and also has a"
<<"\n\tshop for sports goods.There are world-class restrooms and showers"
<<"\n\ta canteen  with lots of  nutritiuous food  items for the  growing"
<<"\n\tplayers.There is also a 24-hour security in the academy.\n"
<<"\n\n\n\tThe institution also provides its customers with a membership fa-"
<<"\n\tcility(either monthly,yearly or lifetime) so that they can easily"
<<"\n\tpay  once and take the pleasure of every sport and every facility"
<<"\n\twe have.\n"
<<"\n\n\tHope You Have a MARVELOUS time in our Academy !!!\n\n"
<<"\n\t\t\t    **********************"
<<"\n\t\t\t      ****************";
getche();
}
void yamuna::sports()
{
    sportmenu:
    clrscr();
    int a,b,e,f;
    char c,d;
    cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
<<"\t\t\t  ****** ****** *******\n"
<<"\t\t        ***********************\n\n\n"
<<"\t\t\t        ******\n"
<<"\t\t\t        * **** *\n"
<<"\t\t\t      **SPORTS**\n"
<<"\t\t\t        * **** *\n"
<<"\t\t\t        ******\n\n\n\n\n\n\n"
<<"\t\t\t1)CRICKET\n\n\n"
<<"\t\t\t2)FOOTBALL\n\n\n"
<<"\t\t\t3)BASKETBALL\n\n\n"
<<"\t\t\t4)LAWN TENNIS\n\n\n"
<<"\t\t\t5)SWIMMING\n\n\n"
<<"\t\t\t6)ATHELETICS\n\n\n"
<<"\t\t\t7)EXIT\n\n\n"
<<"\t\t\tEnter Your Choice: ";
    cin>>a;
    if(a==1)
    {
      cricket:
      clrscr();
      cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
  <<"\t\t\t  ****** ****** *******\n"
  <<"\t\t        ***********************\n\n"
  <<"\t\t\t        ******\n"
  <<"\t\t\t        * **** *\n"
  <<"\t\t\t      **SPORTS**\n"
  <<"\t\t\t        * **** *\n"
  <<"\t\t\t        ******\n\n\n"
  <<"\t\t              *  *  *  *  *  \n"
  <<"\t\t            ** ** ** ** ** ** \n"
  <<"\t\t\t  C  R  I  C  K  E  T\n"
  <<"\t\t            ** ** ** ** ** ** \n"
  <<"\t\t              *  *  *  *  *  \n\n\n\n"
  <<"\tThe cricket academy also known a Gambhir's Academy has the privi-\n"
  <<"\tlage of hosting the Ranji Trophy in its YSA Stadium and is famous-\n"
  <<"\tfor producing legends like Sehwag, Ashish Nehra, Virat Kohli and\n"
  <<"\tmany more.\n\n\n"
  <<"\tEnter your age(b/w5-20) ";
      cin>>age;
      if(age>=5 && age<=12)
cout<<"\tYour fees would be :-Rs.800/-per month";
      else if(age>12 && age<=20)
cout<<"\tYour fees would be :-Rs.1000/-per month";
      else
      {
cout<<"\tYou have entered a wrong age\n"
    <<"\tPress 1 to re-enter your age ";
cin>>b;
if(b==1)
  goto cricket;
else
  goto sportmenu;
      }
      cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
      cin>>c;
      if(c=='y'||c=='Y')
      {
Ycricket:
clrscr();
//DATA OF THE CUSTOMER
cout<<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t  C  R  I  C  K  E  T\n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n"
    <<"\tEnter Your Name ";
cin>>name;
/*cout<<"\n\n\tEnter Your address ";
/*cin>>address;*/
cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
cin>>d;
if(age>=5 && age<=12 && (d=='m'|| d=='M'))
  {
    cout<<"\n\n\tYour timings are:- 9:00a.m.to10:30a.m."
<<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else if(age>=5 && age<=12 && (d=='e' || d=='E'))
  {
    cout<<"\n\n\tYour timings are:- 4:30p.m.to6:00p.m."
<<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='m'|| d=='M'))
  {
  cout<<"\n\n\tYour timings are:-6:30a.m.to8:00a.m."
      <<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='e'|| d=='E'))
  {
  cout<<"\n\n\tYour timings are:-5:30p.m.to7:00p.m."
      <<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else
  {
  cout<<"\n\n\tYou have entered a wrong choice";
  cout<<"\n\n\tPress 1 to continue";
  cin>>e;
  if(e==1)
  goto Ycricket;
  else
  goto Ycricket;
  }
// DATA OF HEAD OF CRICKET

  cout<<"\n\n\tFACULTY:"
      <<"\n\t\tHEAD- Mr.Lalit Sahu"
      <<"\n\t\tCOACH- Mr.Gopal Gupta"
      <<"\n\n\t EQUIPMENTS REQUIRED"
      <<"\n\t\t1)Cricket Kit"
      <<"\n\t\t2)Jersey"
      <<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
  cin>>f;
  if(f==0)
  goto sportmenu;
  else
  goto sportmenu;
  }
  else
  goto sportmenu;
}
if(a==2)
{
  football:
  clrscr();
  cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n"
    <<"\t\t\t        ******\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t      **SPORTS**\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t        ******\n\n\n"
    <<"\t\t          *  *  *  *  *  *  *\n"
    <<"\t\t        ** ** ** ** ** ** ** **\n"
    <<"\t\t\t  F  O  O  T  B  A  L  L\n"
    <<"\t\t        ** ** ** ** ** ** ** **\n"
    <<"\t\t          *  *  *  *  *  *  *\n\n\n\n"
    <<"\tThe football academy also known a Messi's Academy has the privi-\n"
    <<"\tlage of hosting the Asia Cup in  its  YSA Stadium and is famous-\n"
    <<"\tfor producing legends like Sunil Chhetri, Ronaldo,Ibrahimovic and\n"
    <<"\tmany more.\n\n\n"
    <<"\tEnter your age(b/w5-20) ";
  cin>>age;
  if(age>=5 && age<=12)
  cout<<"\tYour fees would be :-Rs.800/-per month";
  else if(age>12 && age<=20)
  cout<<"\tYour fees would be :-Rs.1000/-per month";
  else
  {
  cout<<"\tYou have entered a wrong age\n"
      <<"\tPress 1 to re-enter your age ";
  cin>>b;
  if(b==1)
  goto football;
  else
  goto sportmenu;
  }
  cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>c;
  if(c=='y'||c=='Y')
  {
  Yfootball:
  clrscr();
  cout<<"\t\t          *  *  *  *  *  *  *\n"
    <<"\t\t        ** ** ** ** ** ** ** **\n"
    <<"\t\t\tF  O  O  O  T  B  A  L  L\n"
    <<"\t\t        ** ** ** ** ** ** ** **\n"
    <<"\t\t          *  *  *  *  *  *  *\n\n\n\n"
    <<"\tEnter Your Name ";
  cin>>name;
  /*cout<<"\n\n\tEnter Your address ";
  /*cin>>address;*/
  cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
  cin>>d;
  if(age>=5 && age<=12 && (d=='m' || d=='M'))
  {
    cout<<"\n\n\tYour timings are:- 9:00a.m.to10:30a.m."
<<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else if(age>=5 && age<=12 && (d=='e'|| d=='E'))
  {
    cout<<"\n\n\tYour timings are:- 4:30p.m.to6:00p.m."
<<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
}
  else if(age>12 && age<=20 && (d=='m'|| d=='M'))
  {
  cout<<"\n\n\tYour timings are:-6:30a.m.to8:00a.m."
      <<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='e' || d=='E'))
  {
  cout<<"\n\n\tYour timings are:-5:30p.m.to7:00p.m."
      <<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else
  {
  cout<<"\n\n\tYou have entered a wrong choice";
  cout<<"\n\n\tPress 1 to continue";
  cin>>e;
  if(e==1)
  goto Yfootball;
  else
  goto Yfootball;
  }
// DATA OF HEAD OF FOOTBALL

  cout<<"\n\n\tFACULTY:"
      <<"\n\t\tHEAD- Mr.Kunal Dhoundial"
      <<"\n\t\tCOACH- Mr.Abhishek Rawat"
      <<"\n\n\t EQUIPMENTS REQUIRED"
      <<"\n\t\t1)Studs"
      <<"\n\t\t2)Jersey"
      <<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
  cin>>f;
  if(f==0)
  goto sportmenu;
  else
  goto sportmenu;
  }
  else
  goto sportmenu;
}
if(a==3)
{
  basketball:
  clrscr();
  cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n"
    <<"\t\t\t        ******\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t      **SPORTS**\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t        ******\n\n\n"
    <<"\t\t          *  *  *  *  *  *  *  *\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t\tB  A  S  K  E  T  B  A  L  L\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t          *  *  *  *  *  *  *  *\n\n\n\n"
    <<"\tThe basketball academy also known a Jordans Academy has the privi-\n"
    <<"\tlage of hosting the ABSI Cup in  its  YSA Stadium and is famous-\n"
    <<"\tfor producing legends like Kobe Bryant,Mahesh Bhatt,Fabregas and\n"
    <<"\tmany more.\n\n\n"
    <<"\tEnter your age(b/w5-20) ";
  cin>>age;
  if(age>=5 && age<=12)
  cout<<"\tYour fees would be :-Rs.800/-per month";
  else if(age>12 && age<=20)
  cout<<"\tYour fees would be :-Rs.1000/-per month";
  else
  {
  cout<<"\tYou have entered a wrong age\n"
      <<"\tPress 1 to re-enter your age ";
  cin>>b;
  if(b==1)
  goto basketball;
  else
  goto sportmenu;
  }
  cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>c;
 if(c=='y'||c=='Y')
  {
  Ybasketball:
  clrscr();
  cout<<"\t\t          *  *  *  *  *  *  *  *\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t\tB  A  S  K  E  T  B  A  L  L\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t          *  *  *  *  *  *  *  *\n\n\n\n"
    <<"\tEnter Your Name ";
  cin>>name;
/*  cout<<"\n\n\tEnter Your address ";
  cin>>address;*/
  cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
  cin>>d;
  if(age>=5 && age<=12 && (d=='m'|| d=='M'))
  {
    cout<<"\n\n\tYour timings are:- 9:00a.m.to10:30a.m."
<<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else if(age>=5 && age<=12 && (d=='e'|| d=='E'))
  {
    cout<<"\n\n\tYour timings are:- 4:30p.m.to6:00p.m."
<<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
}
  else if(age>12 && age<=20 && (d=='m'|| d=='M'))
  {
  cout<<"\n\n\tYour timings are:-6:30a.m.to8:00a.m."
      <<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='e'|| d=='E'))
  {
  cout<<"\n\n\tYour timings are:-5:30p.m.to7:00p.m."
      <<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else
  {
  cout<<"\n\n\tYou have entered a wrong choice";
  cout<<"\n\n\tPress 1 to continue";
  cin>>e;
  if(e==1)
  goto Ybasketball;
  else
  goto Ybasketball;
  }
// DATA OF HEAD OF BASKETBALL

  cout<<"\n\n\tFACULTY:"
      <<"\n\t\tHEAD- Mr.Deepanshu Batra"
      <<"\n\t\tCOACH- Mr.Piyush Gupta"
      <<"\n\n\t EQUIPMENTS REQUIRED"
      <<"\n\t\t1)Basket Ball"
      <<"\n\t\t2)Jersey"
      <<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
  cin>>f;
  if(f==0)
  goto sportmenu;
  else
  goto sportmenu;
  }
  else
  goto sportmenu;
}
if(a==4)
{
  lawntennis:
  clrscr();
  cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n"
    <<"\t\t\t        ******\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t      **SPORTS**\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t        ******\n\n\n"
    <<"\t\t          *  *  *  *  *  *  *  *\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t\tL  A  W  N  T  E  N  N  I  S\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t          *  *  *  *  *  *  *  *\n\n\n\n"
    <<"\tThe Tennis  academy also known a Sania's Academy has the privi-\n"
    <<"\tlage of hosting the Delhi Cup in  its YSA Stadium and is famous-\n"
    <<"\tfor producing legends like Sania Mirza,Mahesh Bhupathi, Paes and\n"
    <<"\tmany more.\n\n\n"
    <<"\tEnter your age(b/w5-20) ";
  cin>>age;
  if(age>=5 && age<=12)
  cout<<"\tYour fees would be :-Rs.800/-per month";
  else if(age>12 && age<=20)
  cout<<"\tYour fees would be :-Rs.1000/-per month";
  else
  {
  cout<<"\tYou have entered a wrong age\n"
      <<"\tPress 1 to re-enter your age ";
  cin>>b;
  if(b==1)
  goto lawntennis;
  else
  goto sportmenu;
  }
  cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>c;
 if(c=='y'||c=='Y')
  {
  Ylawntennis:
  clrscr();
  cout<<"\t\t          *  *  *  *  *  *  *  *\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t\tL  A  W  N  T  E  N  N  I  S\n"
    <<"\t\t        ** ** ** ** ** ** ** ** **\n"
    <<"\t\t          *  *  *  *  *  *  *  *\n\n\n\n"
    <<"\tEnter Your Name ";
  cin>>name;
 /* cout<<"\n\n\tEnter Your address ";
  cin>>address;*/
  cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
  cin>>d;
  if(age>=5 && age<=12 && (d=='m'|| d=='M'))
  {
    cout<<"\n\n\tYour timings are:- 9:00a.m.to10:30a.m."
<<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else if(age>=5 && age<=12 && (d=='e'|| d=='E'))
  {
    cout<<"\n\n\tYour timings are:- 4:30p.m.to6:00p.m."
<<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
}
  else if(age>12 && age<=20 && (d=='m'|| d=='M'))
  {
  cout<<"\n\n\tYour timings are:-6:30a.m.to8:00a.m."
      <<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='e'|| d=='E'))
  {
  cout<<"\n\n\tYour timings are:-5:30p.m.to7:00p.m."
      <<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else
  {
  cout<<"\n\n\tYou have entered a wrong choice";
  cout<<"\n\n\tPress 1 to continue";
  cin>>e;
  if(e==1)
  goto Ylawntennis;
  else
  goto Ylawntennis;
  }
// DATA OF HEAD OF LAWNTENNIS

  cout<<"\n\n\tFACULTY:"
      <<"\n\t\tHEAD- Mr.Rakshit Singhal"
      <<"\n\t\tCOACH- Msr.Shivani Singhal"
      <<"\n\n\t EQUIPMENTS REQUIRED"
      <<"\n\t\t1)Racket"
      <<"\n\t\t2)Tennis balls"
      <<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
  cin>>f;
  if(f==0)
  goto sportmenu;
  else
  goto sportmenu;
  }
  else
  goto sportmenu;
}
if(a==5)
{
  swimming:
  clrscr();
  cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n"
    <<"\t\t\t        ******\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t      **SPORTS**\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t        ******\n\n\n"
    <<"\t\t          *  *  *  *  *  *  \n"
    <<"\t\t        ** ** ** ** ** ** ** \n"
    <<"\t\t\tS  W  I  M  M  I  N  G\n"
    <<"\t\t        ** ** ** ** ** ** ** \n"
    <<"\t\t          *  *  *  *  *  *  \n\n\n\n"
    <<"\tThe swimming academy also known a Daksh's Academy has the privi-\n"
    <<"\tlage of hosting the Delhi Trophy in its YSA Pools and is famous-\n"
    <<"\tfor producing legends like Tushar Makhija,Saurabh Jain,Apoorv and\n"
    <<"\tmany more.\n\n\n"
    <<"\tEnter your age(b/w5-20) ";
  cin>>age;
  if(age>=5 && age<=12)
  cout<<"\tYour fees would be :-Rs.800/-per month";
  else if(age>12 && age<=20)
  cout<<"\tYour fees would be :-Rs.1000/-per month";
  else
  {
  cout<<"\tYou have entered a wrong age\n"
      <<"\tPress 1 to re-enter your age ";
  cin>>b;
  if(b==1)
  goto swimming;
  else
  goto sportmenu;
  }
  cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>c;
  if(c=='y'||c=='Y')
  {
  Yswimming:
  clrscr();
  cout<<"\t\t          *  *  *  *  *  *  \n"
    <<"\t\t        ** ** ** ** ** ** ** \n"
    <<"\t\t\tS  W  I  M  M  I  N  G\n"
    <<"\t\t        ** ** ** ** ** ** ** \n"
    <<"\t\t          *  *  *  *  *  *  \n\n\n\n"
    <<"\tEnter Your Name ";
  cin>>name;
  /*cout<<"\n\n\tEnter Your address ";
  cin>>address;*/
  cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
  cin>>d;
  if(age>=5 && age<=12 && (d=='m'|| d=='M'))
  {
    cout<<"\n\n\tYour timings are:- 9:00a.m.to10:30a.m."
<<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else if(age>=5 && age<=12 && (d=='e'|| d=='E'))
  {
    cout<<"\n\n\tYour timings are:- 4:30p.m.to6:00p.m."
<<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
}
  else if(age>12 && age<=20 && (d=='m' || d=='M'))
  {
  cout<<"\n\n\tYour timings are:-6:30a.m.to8:00a.m."
      <<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='e'|| d=='E'))
  {
  cout<<"\n\n\tYour timings are:-5:30p.m.to7:00p.m."
      <<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else
  {
  cout<<"\n\n\tYou have entered a wrong choice";
  cout<<"\n\n\tPress 1 to continue";
  cin>>e;
  if(e==1)
  goto Yswimming;
  else
  goto Yswimming;
  }
// DATA OF HEAD OF SWIMMING

  cout<<"\n\n\tFACULTY:"
      <<"\n\t\tHEAD- Mr.Nishchal Kumar"
      <<"\n\t\tCOACH- Msr.Meha Bareja"
      <<"\n\n\t EQUIPMENTS REQUIRED"
      <<"\n\t\t1)Swimming Costume"
      <<"\n\t\t2)Gears"
      <<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
  cin>>f;
  if(f==0)
  goto sportmenu;
  else
  goto sportmenu;
  }
  else
  goto sportmenu;
}
if(a==6)
{
  atheletics:
  clrscr();
  cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n"
    <<"\t\t\t        ******\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t      **SPORTS**\n"
    <<"\t\t\t        * **** *\n"
    <<"\t\t\t        ******\n\n\n"
    <<"\t\t          *  *  *  *  *  *  *  *  \n"
    <<"\t\t        ** ** ** ** ** ** ** ** **  \n"
    <<"\t\t\tA  T  H  E  L  E  T  I  C  S\n"
    <<"\t\t        ** ** ** ** ** ** ** ** ** \n"
    <<"\t\t          *  *  *  *  *  *  *  *  \n\n\n\n"
    <<"\tThe atheletics academy also known a Bagla's Academy has the privi-\n"
    <<"\tlage of hosting the SRK  Trophy in its YSAm Tracks and is famous-\n"
    <<"\tfor producing legends like Shashank Sharma,Vidit Shah,Osama B and\n"
    <<"\tmany more.\n\n\n"
    <<"\tEnter your age(b/w5-20) ";
  cin>>age;
  if(age>=5 && age<=12)
  cout<<"\tYour fees would be :-Rs.800/-per month";
  else if(age>12 && age<=20)
  cout<<"\tYour fees would be :-Rs.1000/-per month";
  else
  {
  cout<<"\tYou have entered a wrong age\n"
      <<"\tPress 1 to re-enter your age ";
  cin>>b;
  if(b==1)
  goto atheletics;
  else
  goto sportmenu;
  }
  cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>c;
 if(c=='y'||c=='Y')
  {
  Yatheletics:
  clrscr();
  cout<<"\t\t          *  *  *  *  *  *  *  *  \n"
    <<"\t\t        ** ** ** ** ** ** ** ** ** \n"
    <<"\t\t\tA  T  H  E  L  E  T  I  C  S\n"
    <<"\t\t        ** ** ** ** ** ** ** ** ** \n"
    <<"\t\t          *  *  *  *  *  *  *  *  \n\n\n\n"
    <<"\tEnter Your Name ";
  cin>>name;
  /*cout<<"\n\n\tEnter Your address ";
  cin>>address;*/
  cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
  cin>>d;
  if(age>=5 && age<=12 && (d=='m'|| d=='M'))
  {
    cout<<"\n\n\tYour timings are:- 9:00a.m.to10:30a.m."
<<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else if(age>=5 && age<=12 && (d=='e'|| d=='E'))
  {
    cout<<"\n\n\tYour timings are:- 4:30p.m.to6:00p.m."
<<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
}
  else if(age>12 && age<=20 && (d=='m'|| d=='M'))
  {
  cout<<"\n\n\tYour timings are:-6:30a.m.to8:00a.m."
      <<"\n\n\tYour days are:-Tuesday,Thursday,Saturday";
  }
  else if(age>12 && age<=20 && (d=='e'|| d=='E'))
  {
  cout<<"\n\n\tYour timings are:-5:30p.m.to7:00p.m."
      <<"\n\n\tYour days are:-Monday,Wednesday,Friday";
  }
  else
  {
  cout<<"\n\n\tYou have entered a wrong choice";
  cout<<"\n\n\tPress 1 to continue";
  cin>>e;
  if(e==1)
  goto Yatheletics;
  else
  goto Yatheletics;
  }
// DATA OF HEAD OF ATHELETICS
  cout<<"\n\n\tFACULTY:"
      <<"\n\t\tHEAD- Mr.Deepak Gupta"
      <<"\n\t\tCOACH- Mrs.Pooja Gupta"
      <<"\n\n\t EQUIPMENTS REQUIRED"
      <<"\n\t\t1)Shorts"
      <<"\n\t\t2)Sport shoes"
      <<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
  cin>>f;
  if(f==0)
  goto sportmenu;
  else
  goto sportmenu;
  }
  else
  goto sportmenu;
  }
}
void yamuna::facilities()
{
  clrscr();

  cout<<"\n\t\t\t  * * * * * * * * * * *"
      <<"\n\t\t\t  * * * * * * * * * *"
      <<"\n\t\t\t  YAMUNA SPORTS ACADEMY"
      <<"\n\t\t\t  * * * * * * * * * *"
      <<"\n\t\t\t  * * * * * * * * * * *\n\n\n\n"
      <<"\t\t\t      ************\n"
      <<"\t\t\t      *FACILITIES*\n"
      <<"\t\t\t      ************\n\n\n\n\n"
      <<"\tThese are the following facilities provided by this academy:-\n\n\n"
      <<"\t1)CANTEEN/SHOP\n"
      <<"\t\tThe canteen here is owned by Haldiram's and is open 24-hours\n"
      <<"\t\tand provides lots of tasty but nutritious food items at very\n"
      <<"\t\taffordable prices for the young champions. The sports  goods\n"
      <<"\t\tis owned by Nike's and provides best  quality equipments for\n"
      <<"\t\tall sports.\n\n\n\n"
      <<"\t2)SECURITY/PARKING\n"
      <<"\t\tThe whole campus of the academy(including parking is guarded\n"
      <<"\t\tby black cat commandos and CRPF and is purely safe for young\n"
      <<"\t\tstars.The parking here can accomodate every kind of  vehicle\n"
      <<"\t\tand the vehicles are guarded by security.\n\n\n\n";
      getche();
      cout<<"\t3)RESTROOMS/SHOWERS\n"
      <<"\t\tThe restrooms here are purely neat and clean and are equiped\n"
      <<"\t\twith every facilities of modern days and the showers provide\n"
      <<"\t\tthe qualities of facilities for the children to take  shower\n"
      <<"\t\tafter swimming\n\n\n"
      <<"\t\t\t      *    *    *\n " ;
getche();
}
void yamuna::contactus()
{
  clrscr();
  cout<<"\n"
      <<"\t\t\t      ____________________\n"
       <<"\t\t\t    **********************\n"
      <<"\t\t\t    **C O N T A C T  U S**\n"
      <<"\t\t\t    **********************\n"
      <<"\t\t\t    HEAD OFFICE:-\n"
      <<"\t\t\t    Yamuna Sports Academy\n"
      <<"\t\t\t    502 Dayanand Vihar,PNo-708\n"
      <<"\t\t\t    Block-A,Delhi-110092\n"
      <<"\t\t\t    Ph No-011-22230267\n"
// DATA OF HEAD OF PARTICULAR SPORTS
      <<"\t1)CRICKET HEAD                            2)FOOTBALL HEAD\n"
      <<"\t  Mr.Lalit Sahu                            Mr.Kunal Dhoundial\n"
      <<"\t  79 Azad Appts.,Delhi-92,                  54 A-Block,Mayur Vihar\n"
      <<"\t  Ph no-22452343                            Ph no-9946763123\n\n"
      <<"\t3)BASKETBALL HEAD                        4)LAWN TENNIS HEAD\n"
      <<"\t  Mr.Deepanshu Batra                        Mr.Rakshit Singhal\n"
      <<"\t  86 Jai Appts.,Delhi-32                    12,Chander Vihar\n"
      <<"\t  Ph no-9834567834                          Ph no-9868231658\n\n"
      <<"\t5)SWIMMING HEAD                          6)ATHELETICS HEAD\n"
      <<"\t  Mr.Nishchal Kumar                        Mr.Deepak Kumar\n"
      <<"\t  52 Meena Appts,Delhi-01                  45,Krishna Nagar\n"
      <<"\t  Ph no-011 22230365                        Ph no-9998844733\n\n"
      <<"\t\t\t    OUR TOLL-FREE NO:-\n"
      <<"\t\t\t    011-22424242-9";
getche();

}
void yamuna::membership()
{  void write_file();
    void read_file();
    void search();
    void modify();
    void Delete();
    int c;
    int a,d;
    char b;
    Ymembership:
    clrscr();
    cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
<<"\t\t\t  ****** ****** *******\n"
<<"\t\t        ***********************\n"
<<"\t\t\t _____________________\n"
<<"\t\t\t |M E M B E R S H I P|\n"
<<"\t\t\t _____________________\n\n"
<<"\t\t\t1)MONTHLY MEMBERSHIP\n\n\n"
<<"\t\t\t2)YEARLY MEMBERSHIP\n\n\n"
<<"\t\t\t3)LIFETIME MEMBERSHIP\n\n\n"
<<"\t\t\t4)FOR ADMINISTRATOR ONLY\n\n\n"
<<"\t\t\t5)EXIT\n\n\n"
<<"\t\t\tEnter Your Choice: ";
    cin>>a;
    if(a==1)
    {
      clrscr();
      cout <<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
  <<"\t\t\t  ****** ****** *******\n"
  <<"\t\t        ***********************\n\n\n"
    <<"\t\t\t _____________________\n\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n\n\n"
    <<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t  M  O  N  T  H  L  Y\n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n"
    <<"\tMonthly membership is very usefull.\n"
    <<"\tIf you will take monthly membership then you can leave\n"
    <<"\tit any time if u want to. In this u will get some facilities\n"
    <<"\tlike you can do swimming any time free of cost.\n"
    <<"\tthe fees for monthly member ship is Rs.2500\month.\n";


  cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>b;
if(b=='y'||b=='Y')
{

clrscr();
cout <<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n\n"
    <<"\t\t\t _____________________\n\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n\n\n"
    <<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t  M  O  N  T  H  L  Y\n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n";
    write_file();
    cout<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
    cin>>d;

  if(d==0)
  goto Ymembership;
  else
  goto Ymembership;

  }
  else
  goto Ymembership;
}
if(a==2)
{clrscr();
cout <<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n\n"
    <<"\t\t\t _____________________\n\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n\n\n"
    <<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t    Y  E  A  R  L  Y \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n"
    <<"\tYearly member ship is again a beneficial membersip.\n"
    <<"\tin this u pay every year no problem of month charges.\n"
    <<"\tIn this also you can do swimming any time & have 520hrs extra.\n"
    <<"\tFees for yearly membership is Rs.11000\annum only.\n";
cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
  cin>>b;
 if(b=='y'||b=='Y')
{
clrscr();
cout <<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n"
    <<"\t\t\t _____________________\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n\n"
    <<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t    Y  E  A  R  L  Y \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n";
    write_file();
  cout<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
      <<"\n\n\tPress 0 to continue";
    cin>>d;
  if(d==0)
    goto Ymembership;
  else
    goto Ymembership;
  }
  else
  goto Ymembership;
}
if(a==3)
{clrscr();
cout <<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n\n"
    <<"\t\t\t _____________________\n\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n\n\n"
    <<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t  L  I  F  E  T  I  M  E\n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n"
    <<"\tLifetime member ship is very beneficial.Moneywise and facilities as well\n"
    <<"\tIf u are interested in life time membership then carry ur id proof.\n"
    <<"\tFees for lifetime membership is for just Rs.60,000 once \n";
cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
cin>>b;
if(b=='y'||b=='Y')
{
  clrscr();
  cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n\n\n"
    <<"\t\t\t _____________________\n\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n\n\n"
    <<"\t\t              *  *  *  *  *  \n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t\t  L  I  F  E  T  I  M  E\n"
    <<"\t\t            ** ** ** ** ** ** \n"
    <<"\t\t              *  *  *  *  *  \n\n\n\n";
    write_file();
cout<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
    <<"\n\n\tPress 0 to continue";
cin>>d;
if(d==0)
  goto Ymembership;
else
  goto Ymembership;
}
else
  goto Ymembership;
}
if(a==4)
{
clrscr();
do
{
cout<<"\n\n\n\t\t\t  YAMUNA SPORTS ACADEMY\n"
    <<"\t\t\t  ****** ****** *******\n"
    <<"\t\t        ***********************\n"
    <<"\t\t\t _____________________\n"
    <<"\t\t\t |M E M B E R S H I P|\n"
    <<"\t\t\t _____________________\n"
    <<"\t\t      FOR THE ADMINISTRATOR ONLY\n"
    <<"\t\t    ******************************\n";
 cout<<"\n\t\t1.Add Members\n"
    <<"\n\t\t2.Display Members\n"
    <<"\n\t\t3.Search Members\n"
    <<"\n\t\t4.Modify Members\n"
    <<"\n\t\t5.Delete Members\n"
    <<"\n\t\t6.Exit\n"
    <<"\n\t\tEnter your selection: ";
    cin>>c;
    if(c==1)
    write_file();
    else if(c==2)
    read_file();
    else if(c==3)
    search();
    else if(c==4)
    modify();
    else if(c==5)
    Delete();
     }
    while(c!=6);
    /*getche();*/
}
}
void main()
{
// STARTING PAGE
  mainmenu:

  clrscr();
  int h;
  char x,j;
  yamuna y;
// MAIN OPTIONS
  cout<<"\n\t      ***************************************************\n"
      <<"\t      *  _____________________________________________  *\n"
      <<"\t      *    _________________________________________    *\n"
      <<"\t      *                                                *\n"
      <<"\t      *    Y A M U N A  S P O R T S  A C A D E M Y    *\n"
      <<"\t      *    _________________________________________    *\n"
      <<"\t      *  _____________________________________________  *\n"
      <<"\t      *                                                *\n"
      <<"\t      *    502, Dayanand Vihar, Plot No.708, Block-A    *\n"
      <<"\t      *    New Delhi-110092, Phone No.- 011-22230267    *\n"
      <<"\t      * _______________________________________________ *\n"
      <<"\t      *_________________________________________________*\n"
      <<"\t      *                                                *\n"
      <<"\t      ***************************************************\n\n\n\n"
      <<"\t      WELCOME TO YAMUNA SPORTS ACADEMY ! ! !\n\n\n\n"
      <<"\t      1)  A B O U T  U S\n\n\n"
      <<"\t      2)  S P O R T S\n\n\n"
      <<"\t      3)  F A C I L I T I E S\n\n\n"
      <<"\t      4)  M E M B E R S H I P\n\n\n"
      <<"\t      5)  C O N T A C T  U S\n\n\n"
      <<"\t      6)  E X I T\n\n\n"
      <<"\t      ENTER YOUR CHOICE: ";
  cin>>h;
// FOR GOING TO THE SPECIFIED OPTION
  if(h==1)
  y.aboutus();
  if(h==2)
  y.sports();
  if(h==3)
  y.facilities();
  if(h==5)
  y.contactus();
  if(h==4)
  y.membership();
  if(h==6)
  {
  exit(0);
  }
  else if(h!=1 && h!=2 && h!=3 &&h!=5 && h!=4 && h!=6)
  goto mainmenu;
 /* cout<<"\n\n\t      Press any key to continue ";
  cin>>j;*/
  goto mainmenu;
  /*getche();*/
  }
