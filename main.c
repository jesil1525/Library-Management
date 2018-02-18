#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


void admin();
void admin_login();
void add();
void view();
int bookid(int);
void del();
void edit();
void uadd();
int userid(int);
void uview();
void udel();
void uedit();
void search();
void usearch();
void issue();
void issuerec();
void uprofile();
void ret();
void user();
void user_login();
void profile();




struct user
{
	int uid;
	char uname[20];
	char dob[20];
	 long int contact;
}u;



struct book
{
	int id;
	char name[10];
	char aname[10];
	int quantity;
	int rack;
	char cat[20];
	int left;
	int taken;
}b;

struct issue
{
	char date[20];
	char ret[20];
	int userid;
	int bookid;
	char username[20];
	char bookname[10];
}i;

int main()
{
	int o;
	printf("\nWElCOME TO AAA LIBRARY\n");
	printf("\n1.Login as Administrator\n2.Login As User\n3.Exit\nYour Choice:");
	scanf("%d",&o);
	switch(o)
	{
		case 1: admin_login();
		break;
		case 2: user_login();
	    break;
	    case 3:exit(0);
		default: main();
		
	}
	return 0;
}

void admin_login()
{
	 int i=0,o;
	 char ch,ap[10],eap[10];
	 strcpy(ap,"a123");
	 printf("\nWelcome Administrator");
	 printf("\nEnter Password:");
	 do
	 {
	 	ch=getch();
	 	if(ch!=13)
	 	{
	 	   eap[i]=ch;
	 	   printf("*");
	 	   i++;
		}
		else
		   eap[i]=NULL;
	 }while(ch!=13);
	 if(strcmp(ap,eap)==0)
	 {
	 	admin();
	 	
	 }
	 else
	 {
	 	printf("\nInvalid Password!!");
	 	printf("\n1.Retry\n2.Go To Home\nYour Choice:");
	 	scanf("%d",&o);
	 	switch(o)
	 	{
	 		case 1: admin_login();
	 		break;
	 		case 2: main();
	 		break;
	 		default: main();
		 }
	 }
}

void admin()
{
	int o;
	printf("\nWELCOME ADMINISTRATOR");
	printf("\n1.Add Book\n2.Edit Book\n3.Delete Book\n4.View Books\n5.Add Member\n6.Edit Member\n7.Delete Member\n8.View Members\n9.Search Book\n10.Search User\n11.Issue Book\n12.Return Book\n13.Issue Record\n14.User Profile\nYour Choice:");
	scanf("%d",&o);
	switch(o)
	{
		case 1: add();
		break;
		case 2:edit();
		break;
		case 3:del();
		break;
		case 4:view();
		break;
		case 5:uadd();
		break;
		case 6: uedit();
		break;
		case 7: udel();
		break;
		case 8:uview();
		break;
		case 9: search();
		break;
		case 10: usearch();
		break;
		case 11: issue();
		break;	
		case 12: ret();
		break;
		case 13:issuerec();
		break;
		case 14: uprofile();
		break;
		case 15: main();
		break;
		default: admin();
	}
	
}

void add()
{
	FILE *f1;
	int no,o;
    f1=fopen("book.dat","a+");
	printf("\nEnter a Unique Book ID: ");
	scanf("%d",&no);
	if(bookid(no)==0)
	{
	b.id=no;
	printf("\nEnter Book Name:");
	scanf("%s",b.name);
	printf("\nEnter Author Name:");
	scanf("%s",b.aname);
	printf("\nEnter no. of Copies:");
	scanf("%d",&b.quantity);
	printf("\nEnter Rack no.:");
	scanf("%d",&b.rack);
	printf("\nEnter Category:");
	scanf("%s",b.cat);
	b.left=b.quantity;
	b.taken=0;
	fprintf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
	fclose(f1);
    }
	else
	  add();  
	printf("\nBook Added Successfully!!");
	printf("\n1.Add Book\n2.Go To Menu\nYour Choice:");
	scanf("%d",&o);
	switch(o)
	{
		case 1: add();
		break;
		case 2: admin();
		break;
		default: admin();
	}
}

void view()
{
	FILE *f1;
	int c;
	f1=fopen("book.dat","r");
	printf("\n ID   BOOK NAME   AUTHOR NAME   QUANTITY  RACK   CATEGORY  AVAILABILITY  BORROWED\n");
	while(fscanf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF)
	{
		printf("\n%d     %s        %s          %d          %d      %s     %d            %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
	}
	fclose(f1);
	printf("\n1.Go To Menu\n2.Logout\nYour Choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1: admin();
		break;
		case 2: main();
		break;
		default:admin();
	}
}



int bookid(int id)
{
 FILE *f1;
 int i=0;
 f1=fopen("book.dat","r");
 while(fscanf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF)
 {
 if(b.id==id)
 {
 i=1;
 break;
 }
 }
 fclose(f1);
 return i;
}

void del()
{
	FILE *f1,*f2;
	int no,c;
	printf("\nEnter Book ID To Delete:");
	scanf("%d",&no);
	if(bookid(no)!=0)
	{
        f1=fopen("temp.dat","w");
	    f2=fopen("book.dat","r");	
	    while(fscanf(f2,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF) 
        { 
           if(b.id!=no)
           { 
           fprintf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
           }
        }
        fclose(f1);
        fclose(f2);
        remove("book.dat");
        rename("temp.dat","book.dat");
        printf("\nBook Deleted Successfully!!");
        printf("\n1.Delete Book\n2.Go To Menu\nYour Choice:");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: del();
      	    break;
      	    case 2: admin();
      	    break;
       	    default: admin();
	    }
    }  
	else  
	{
	 	printf("\nBook Does Not Exist!!");
		printf("\n1.Retry\n2.Go To Menu\nYour Choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: del();
			break;
			case 2: admin();
			break;
			default: del();
		}
    }
}

void edit()
{
   FILE *f1,*f2;
   int i=0,o,no,c;
   printf("\nEnter Book ID To Edit:");
   scanf("%d",&no);	
   if(bookid(no)!=0)
   {
   	    f1=fopen("temp.dat","w");
	    f2=fopen("book.dat","r");
	     while(fscanf(f2,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF) 
        { 
           if(b.id!=no)
           { 
           fprintf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
           }
           else
           {
           	b.id=no;
           	printf("\nEnter Book Name:");
           	scanf("%d",&b.id);
           	printf("\nEnter Book Name:");
	        scanf("%s",b.name);
	        printf("\nEnter Author Name:");
	        scanf("%s",b.aname);
         	printf("\nEnter no. of Copies:");
        	scanf("%d",&b.quantity);
	        printf("\nEnter Rack no.:");
         	scanf("%d",&b.rack);
         	printf("\nEnter Category:");
         	scanf("%s",b.cat);
         	b.left=b.quantity;
         	b.taken=0;
	        fprintf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
           	}
        }
        fclose(f1);
        fclose(f2);
        remove("book.dat");
        rename("temp.dat","book.dat");
        printf("\nBook Edited Successfully!!");
        printf("\n1.Edit Book\n2.Go To Menu\nYour Choice:");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: edit();
      	    break;
      	    case 2: admin();
      	    break;
       	    default: admin();
	    }
			
   }
   else
   {
   	printf("\nBook Does Not Exist!!");
		printf("\n1.Retry\n2.Go To Menu\nYour Choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: edit();
			break;
			case 2: admin();
			break;
			default: edit();
		}
   }
}

void uadd()
{
	FILE *f1;
	int no,o;
    f1=fopen("user.dat","a+");
	printf("\nEnter a Unique User ID: ");
	scanf("%d",&no);
	if(userid(no)==0)
	{
	u.uid=no;
	printf("\nEnter User Name:");
	scanf("%s",u.uname);
	printf("\nEnter User D.O.B(dd/mm/yyyy):");
	scanf("%s",u.dob);
	printf("\nEnter Contact Number:");
	scanf("%d",&u.contact);
	fprintf(f1,"\n%d     %s     %s     %d",u.uid,u.uname,u.dob,u.contact);
	fclose(f1);
    }
	else
	  uadd();  
	printf("\nUser Added Successfully!!");
	printf("\n1.Add User\n2.Go To Menu\nYour Choice:");
	scanf("%d",&o);
	switch(o)
	{
		case 1: uadd();
		break;
		case 2: admin();
		break;
		default: admin();
	}
}

int userid(int id)
{
 FILE *f1;
 int i=0;
 f1=fopen("user.dat","r");
 while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
 {
 if(u.uid==id)
 {
 i=1;
 break;
 }
 }
 fclose(f1);
 return i;
}


void uview()
{
	FILE *f1;
	int c;
	f1=fopen("user.dat","r");
	printf("\n ID   USER NAME   DOB        CONTACT\n");
	while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
	{
		printf("\n%d     %s        %s            %d",u.uid,u.uname,u.dob,u.contact);
	}
	fclose(f1);
	printf("\n1.Go To Menu\n2.Logout\nYour Choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1: admin();
		break;
		case 2: main();
		break;
		default:admin();
	}
}


void udel()
{
	FILE *f1,*f2;
	int no,c;
	printf("\nEnter User ID To Delete:");
	scanf("%d",&no);
	if(userid(no)!=0)
	{
        f1=fopen("temp.dat","w");
	    f2=fopen("user.dat","r");	
	    while(fscanf(f2,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF) 
        { 
           if(u.uid!=no)
           { 
           fprintf(f1,"\n%d     %s     %s     %d",u.uid,u.uname,u.dob,u.contact);
           }
        }
        fclose(f1);
        fclose(f2);
        remove("user.dat");
        rename("temp.dat","user.dat");
        printf("\nUser Deleted Successfully!!");
        printf("\n1.Delete User\n2.Go To Menu\nYour Choice:");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: udel();
      	    break;
      	    case 2: admin();
      	    break;
       	    default: admin();
	    }
    }  
	else  
	{
	 	printf("\nUser Does Not Exist!!");
		printf("\n1.Retry\n2.Go To Menu\nYour Choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: udel();
			break;
			case 2: admin();
			break;
			default: udel();
		}
    }
}


void uedit()
{
   FILE *f1,*f2;
   int i=0,o,no,c;
   printf("\nEnter User ID To Edit:");
   scanf("%d",&no);	
   if(userid(no)!=0)
   {
   	    f1=fopen("temp.dat","w");
	    f2=fopen("user.dat","r");
	     while(fscanf(f2,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF) 
        { 
           if(u.uid!=no)
           { 
           fprintf(f1,"\n%d     %s     %s     %d",u.uid,u.uname,u.dob,u.contact);
           }
           else
           {
           	u.uid=no;
           	printf("\nEnter User Name:");
           	scanf("%s",u.uname);
           	printf("\nEnter D.O.B(dd/mm/yyyy):");
	         scanf("%s",u.dob);
	         printf("\nEnter Contact no.:");
         	scanf("%d",&u.contact);
	        fprintf(f1,"\n%d     %s     %s     %d",u.uid,u.uname,u.dob,u.contact);
           	}
        }
        fclose(f1);
        fclose(f2);
        remove("user.dat");
        rename("temp.dat","user.dat");
        printf("\nUser Edited Successfully!!");
        printf("\n1.Edit User\n2.Go To Menu\nYour Choice:");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: uedit();
      	    break;
      	    case 2: admin();
      	    break;
       	    default: admin();
	    }
			
   }
   else
   {
   	printf("\nUser Does Not Exist!!");
		printf("\n1.Retry\n2.Go To Menu\nYour Choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: uedit();
			break;
			case 2: admin();
			break;
			default: uedit();
		}
   }
}


void search()
{ 
  FILE *f1;
  f1=fopen("book.dat","r");
  char text[20];
  int i,no,o,found=0;
  printf("\n1.Search By ID\n2.Search By Name\n3.Search By Category\nYour Choice:");
  scanf("%d",&i);
  switch(i)
  {
  	case 1:
  		{
  			printf("\nEnter Book ID:");
  			scanf("%d",&no);
  			if(bookid(no)!=0)
  			{
  			    while(fscanf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF)
				 {
				 	if(b.id==no)
				 	{
				 		printf("\nBook ID: %d\nBook Name: %s\nAuthor Name: %s\nQuantity: %d\nRack No.: %d\nCategory: %s\nAvailable: %d\nBorrowed: %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
					}
				 }	
			}
			else
			  printf("\nBook Does Not Exists!!");
			printf("\n1.Search Book\n2.Go To Menu\nYour Choice:");
			scanf("%d",&o);
			if(o==1)
			search();
			else
			admin();
		}
		case 2:
		{
		    printf("\nEnter Book Name To Search:");
			scanf("%s",text);
			while(fscanf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF)
			{
			    if(strcmpi(b.name,text)==0)
				{
				   found++;	
				   printf("\nSearch Result:");
				   printf("\nBook ID: %d\nBook Name: %s\nAuthor Name: %s\nQuantity: %d\nRack No.: %d\nCategory: %s\nAvailability: %d\nBorrowed: %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
				}	
			}
			if(found==0)
			    printf("\nBook Does Not Exist!!");
			printf("\n1.Search Book\n2.Go To Menu\nYour Choice:");
			scanf("%d",&o);
			if(o==1)
			search();
			else
			admin();		
		}
		case 3:
		{
			printf("\nEnter Book Category To Search:");
			scanf("%s",text);
			while(fscanf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF)
			{
			    if(strcmpi(b.cat,text)==0)
				{
				   found++;	
				   printf("\nSearch Result:");
				   printf("\nBook ID: %d\nBook Name: %s\nAuthor Name: %s\nQuantity: %d\nRack No.: %d\nCategory: %s\nAvailability: %d\nBorrowed: %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
				}	
			}
			if(found==0)
			    printf("\nBook Does Not Exist!!");
			printf("\n1.Search Book\n2.Go To Menu\nYour Choice:");
			scanf("%d",&o);
			if(o==1)
			search();
			else
			admin();	
		}
		default: search();
  }
  fclose(f1);
}
  
 
 void usearch()
{ 
  FILE *f1;
  f1=fopen("user.dat","r");
  char text[20];
  int i,no,o,found=0;
  printf("\n1.Search By ID\n2.Search By Name\nYour Choice:");
  scanf("%d",&i);
  switch(i)
  {
  	case 1:
  		{
  			printf("\nEnter Book ID:");
  			scanf("%d",&no);
  			if(userid(no)!=0)
  			{
  			    while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
				 {
				 	if(u.uid==no)
				 	{
				 		printf("\nUser ID: %d\nUser Name: %s\nD.O.B: %s\nContact: %d",u.uid,u.uname,u.dob,u.contact);
					}
				 }	
			}
			else
			  printf("\nUser Does Not Exists!!");
			printf("\n1.Search User\n2.Go To Menu\nYour Choice:");
			scanf("%d",&o);
			if(o==1)
			usearch();
			else
			admin();
		}
		case 2:
		{
		    printf("\nEnter User Name To Search:");
			scanf("%s",text);
			while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
			{
			    if(strcmpi(u.uname,text)==0)
				{
				   found++;	
				   printf("\nSearch Result:");
				   printf("\nUser ID: %d\nUser Name: %s\nD.O.B: %s\nContact No.: %d",u.uid,u.uname,u.dob,u.contact);
				}	
			}
			if(found==0)
			    printf("\nUser Does Not Exist!!");
			printf("\n1.Search User\n2.Go To Menu\nYour Choice:");
			scanf("%d",&o);
			if(o==1)
			usearch();
			else
			admin();		
		}
		default: usearch();
  }
  fclose(f1);
}


void issue()
{
	FILE *f1,*f2,*f3,*t1;
	int n1,n2,o;
	f1=fopen("book.dat","r");
	f2=fopen("user.dat","r");
	f3=fopen("issue.dat","a+");
	t1=fopen("temp.dat","w");
	printf("\nEnter Valid User ID:");
	scanf("%d",&n1);
	if(userid(n1)==0)
	{
		issue();
	}
	else
	{   
	    retry:
		printf("\nEnter Book ID:");
		scanf("%d",&n2);
		if(bookid(n2)==0)
		{
			printf("\nBook Does Not Exist!");
			goto retry;
		}
		while(fscanf(f1,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF) 
		{
			if(b.id!=n2)
			{
				fprintf(t1,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
			}
			else
			{
				if(b.left==0)
				{
					printf("\nSorry!Book Not In Stock!!");
					printf("\n1.Retry\n2.Go To Menu\nYour Choice:");
					scanf("%d",&o);
					if(o==1)
					goto retry;
					else
					admin();
				}
				else
				{
				strcpy(i.bookname,b.name);
				b.left--;
				b.taken++;
			    fprintf(t1,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);	
			    } 
			}
			
		}
		while(fscanf(f2,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
		{
			if(u.uid==n1)
		    {
				strcpy(i.username,u.uname);
			}
		}
		i.userid=n1;
		i.bookid=n2;
		printf("\nEnter Today's Date(dd/mm/yyyy):");
		scanf("%s",i.date);
		printf("Enter Return Date(dd/mm/yyyy):");
		scanf("%s",i.ret);
		fprintf(f3,"\n%s     %d     %s     %d     %s     %s",i.date,i.userid,i.username,i.bookid,i.bookname,i.ret);
		
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(t1);
	remove("book.dat");
    rename("temp.dat","book.dat");
    printf("\nBook Issued Successfully!");
		printf("\n1.Issue Book\n2.Go To Menu\nYour Choice:");
		scanf("%d",&o);
		if(o==1)
		issue();
		else
		admin();
}

void issuerec()
{
	FILE *f1;
	
	int c;
	f1=fopen("issue.dat","r");
	printf("\n ISSUE DATE   USER ID   USER NAME   BOOK ID   BOOK NAME    RETURN DATE\n");
	while(fscanf(f1,"\n%s     %d     %s     %d     %s     %s",i.date,&i.userid,i.username,&i.bookid,i.bookname,i.ret)!=EOF)
	{
		printf("\n%s     %d     %s     %d     %s     %s",i.date,i.userid,i.username,i.bookid,i.bookname,i.ret);
	}
	fclose(f1);
	printf("\n1.Go To Menu\n2.Logout\nYour Choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1: admin();
		break;
		case 2: main();
		break;
		default:admin();
	}
}

void ret()
{
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("issue.dat","r");
	f2=fopen("temp.dat","w");
	f3=fopen("boo.dat","r");
	f4=fopen("temp1.dat","w");
	int c,n1,n2;
	printf("\nEnter Valid User ID:");
	scanf("%d",&n1);
	if(userid(n1)==0)
	{
		ret();
	}
	else
	{   
	    retry:
		printf("\nEnter Book ID:");
		scanf("%d",&n2);
		if(bookid(n2)==0)
		goto retry;
		while(fscanf(f1,"\n%s     %d     %s     %d     %s     %s",i.date,&i.userid,i.username,&i.bookid,i.bookname,i.ret)!=EOF)
		{
			if(i.userid!=n1 && i.bookid!=n2)
			{
				fprintf(f2,"\n%s     %d     %s     %d     %s     %s",i.date,i.userid,i.username,i.bookid,i.bookname,i.ret);
			}
		}
			while(fscanf(f3,"\n%d     %s     %s     %d     %d     %s     %d     %d",&b.id,b.name,b.aname,&b.quantity,&b.rack,b.cat,&b.left,&b.taken)!=EOF)
			{
				if(b.id!=n2)
				{
				   fprintf(f4,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);	
				}
				else
				{
					b.left++;
					b.taken--;
					fprintf(f4,"\n%d     %s     %s     %d     %d     %s     %d     %d",b.id,b.name,b.aname,b.quantity,b.rack,b.cat,b.left,b.taken);
				}
			}
    }
		fclose(f1);
        fclose(f2);
        fclose(f3);
        fclose(f4);
        remove("book.dat");
        rename("temp1.dat","book.dat");
        remove("issue.dat");
        rename("temp.dat","issue.dat");
        printf("\nBook Returned Successfully!!");
        printf("\n1.Return Book\n2.Go To Menu\nYour Choice:");
        scanf("%d",&c);
        switch(c)
        {
        	case 1: ret();
      	    break;
      	    case 2: admin();
      	    break;
       	    default: admin();
	    }
	
}

void user()
{   
    int o;
	printf("\nWELCOME USER");
	printf("\n1.Profile\n2.Check Book Availability\nYour Choice:");
	scanf("%d",&o);
	if(o==1)
	profile();
	if(o==2)
	view();
	else
	user();
}


void user_login()
{
	 FILE *f1;
	 int i=0,o,no,found=0;
	 char ch,eup[20];
	 f1=fopen("user.dat","r");
	 printf("\nWELCOME USER");
	 printf("\nEnter ID:");
	 scanf("%d",&no);
	 printf("\nEnter Password(name):");
	 do
	 {
	 	ch=getch();
	 	if(ch!=13)
	 	{
	 	   eup[i]=ch;
	 	   printf("*");
	 	   i++;
		}
		else
		   eup[i]=NULL;
	 }while(ch!=13);
	    while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
	    {
	    	if(u.uid==no && strcmpi(u.uname,eup)==0)
	    	{
	    	user();
	    	found=1;
	        }
		}
	  if(found==0)
	 {
	 	printf("\nInvalid Password!!");
	 	printf("\n1.Retry\n2.Go To Home\nYour Choice:");
	 	scanf("%d",&o);
	 	switch(o)
	 	{
	 		case 1: admin_login();
	 		break;
	 		case 2: main();
	 		break;
	 		default: main();
		 }
	 }
	 fclose(f1);
}


void profile()
{
	FILE *f1,*f2;
	int o,no,found=0;
	f1=fopen("user.dat","r");
	f2=fopen("issue.dat","r");
	printf("\nEnter Your User ID:");
	scanf("%d",&no);
	if(userid(no)==0)
	{
		profile();
	}
	while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
	{
		if(u.uid==no)
		{
			printf("\nID: %d\nName: %s\nD.o.b: %s\nContact: %d",u.uid,u.uname,u.dob,u.contact);
		}
	}
	printf("\nBooks Borrowed:");
	while(fscanf(f2,"\n%s     %d     %s     %d     %s     %s",i.date,&i.userid,i.username,&i.bookid,i.bookname,i.ret)!=EOF)
	{
		if(i.userid==no)
		{
			printf("\nBook ID: %d\nBook Name: %s\nIssue Date: %s\nReturn Date: %s",&i.bookid,i.bookname,i.date,i.ret);
			found=1;
		}
	}
	if(found==0)
	{
		printf("\nNo Books Borrowed!");
	}
	fclose(f1);
	fclose(f2);
	printf("\n1.Go To Menu\n2.Logout");
	scanf("%d",&o);
	if(o==2)
	main();
	else
	user();
	
}

void uprofile()
{
	FILE *f1,*f2;
	int o,no,found=0;
	f1=fopen("user.dat","r");
	f2=fopen("issue.dat","r");
	printf("\nEnter Valid User ID:");
	scanf("%d",&no);
	if(userid(no)==0)
	{
		profile();
	}
	while(fscanf(f1,"\n%d     %s     %s     %d",&u.uid,u.uname,u.dob,&u.contact)!=EOF)
	{
		if(u.uid==no)
		{
			printf("\nID: %d\nName: %s\nD.o.b: %s\nContact: %d",u.uid,u.uname,u.dob,u.contact);
		}
	}
	printf("\nBooks Borrowed:");
	while(fscanf(f2,"\n%s     %d     %s     %d     %s     %s",i.date,&i.userid,i.username,&i.bookid,i.bookname,i.ret)!=EOF)
	{
		if(i.userid==no)
		{
			
			printf("\nBook ID: %d\nBook Name: %s\nIssue Date: %s\nReturn Date: %s",i.bookid,i.bookname,i.date,i.ret);
			found=1;
			
		}
	}
	if(found==0)
	{
		printf("\nNo Books Borrowed!");
	}
	
	fclose(f1);
	fclose(f2);
	printf("\n1.Go To Menu\n2.Logout");
	scanf("%d",&o);
	if(o==2)
	main();
	else
	admin();
	
}




