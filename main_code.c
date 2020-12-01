 #include<stdio.h> 
 #include<string.h> 
 #include<stdlib.h> 
struct student { 
    char reg[15]; 
    char name[15]; 
    char add[25]; 
    char father_name[15]; 
    char mother_name[15]; 
    char department[15]; 
    long int phone_no; 
    char email_id[20]; 
    char catagory[8]; 
    char sex[8]; };
    struct student stu; 
    void record(); 
    void search(); 
    void mod(); 
    void list(); 
    void delete(); 
    int main(){
    int s;
    main: system("cls"); 
    printf("\n\t######## WELCOME TO STUDENT RECORD SYSTEM ########"); 
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=========================\n\n\t\t[1]:ADD NEW RECORD\n\t\t[2]:SEARCH RECORD\n\t\t[3]:MODIFY STUDENT RECORD\n\t\t[4]:DELETE STUDENT RECORD\n\t\t[5]:LIST OF STUDENTS\n\t\t[6]:EXIT\n\t\t========================="); 
    printf("\n\t\tENTER YOUR CHOICE:"); scanf("%d",&s); switch(s) { case 1: record(); break; case 2: search(); break; case 5: list(); break; case 6: printf("\n\t\tARE YOU SURE YOU WANT TO EXIT"); break; case 3: mod(); break; case 4: delete(); break; default: printf("INVALID OPTION"); break; } printf("\n\n\t\t:ENTER ANY CHOICE:\n\n\t[1]:MAIN MENU\t\t[2]:EXIT\n"); scanf("%d",&s);

    switch (s)
        {
                case 1:
                    goto main;
                case 2:
                    break;
                default :
                    printf("INVALID OPTION");
                    break;
            }
} 
void record() 
{ 
    FILE *fp; system("cls"); 
    for(;;) 
        { 
            fp=fopen("student.txt","a+"); 
            fflush(stdin); 
            printf("TO EXIT ENTER BLANK SPACE IN NAME INPUT\n\nNAME[CAPITAL]:"); 
            scanf("%[^\n]",stu.name); 
            if(strcmp(stu.name," ")==0) 
                break; 
            fflush(stdin); 
            printf("\nREGISTRATION NO:"); 
            scanf("%s",stu.reg); 
            fflush(stdin); 
            printf("\nFATHER'S NAME:"); 
            scanf("%[^\n]",stu.father_name); 
            fflush(stdin); 
            printf("\nMOTHER'S NAME:"); 
            scanf("%[^\n]",stu.mother_name); 
            fflush(stdin); printf("\nDEPARTMENT:"); 
            scanf("%s",stu.department); 
            fflush(stdin); 
            printf("\nEMAIL ADDRESS:"); 
            scanf("%s",stu.email_id); 
            fflush(stdin); 
            printf("\nPHONE NO:"); 
            scanf("%ld",&stu.phone_no); 
            fflush(stdin); 
            printf("\nCATAGORY:"); 
            scanf("%s",stu.catagory); 
            fflush(stdin); 
            printf("\nSEX:"); 
            scanf("%s",stu.sex); 
            fflush(stdin); 
            fwrite(&stu,sizeof(stu),1,fp); 
            fclose(fp); 
        } 
    } 
    void search() 
    { 
        FILE *fp; 
        int found=0; 
        char a[35]; 
        system("cls"); 
        fp=fopen("student.txt","r"); 
        if(fp==NULL) 
            { 
                printf("ERROR IN OPENING"); 
                exit(1); 
            } 
            printf("ENTER THE ID OF THE STUDENT:"); 
            fflush(stdin); 
            gets(a);

        while(fread(&stu,sizeof(stu),1,fp) == 1)
            {
                if(strcmp(a,stu.reg)==0)
                    {
                        found=1;
                        break;
                    }
            }
        if(found==1)
            {
                printf("\t########### RECORD IS ###########\n\n");
                printf("\nNAME=%s\nREGISTRATION NO:%s\nFATHER'S NAME:%s\nMOTHER'S NAME:%s\nDEPARTMENT:%s\nEMAIL ADDRESS:%s\nPHONE NO:%Ld\nCATAGORY:%s\nSEX:%s\n\n\n",stu.name,stu.reg,stu.father_name,stu.mother_name,stu.department,stu.email_id,stu.phone_no,stu.catagory,stu.sex);
            }
        else
                printf("SORRY NO RECORD FIND IN DATABASE");
       fclose(fp);
} 
void list() 
{ 
    FILE *fp; 
    system("cls"); 
    fp=fopen("student.txt","r"); 
    if(fp==NULL) 
        { 
            printf("FILE DOES NOT EXIST"); 
            exit(1); 
        }

        printf("\n\t########STUDENT RECORD IS##########");
        while(fread(&stu,sizeof(stu),1,fp)==1)
        {
            printf("\nNAME=%s\nREGISTRATION NO:%s\nFATHER'S NAME:%s\nMOTHER'S NAME:%s\nDEPARTMENT:%s\nEMAIL ADDRESS:%s\nPHONE NO:%ld\nCATAGORY:%s\nSEX:%s\n\n\n",stu.name,stu.reg,stu.father_name,stu.mother_name,stu.department,stu.email_id,stu.phone_no,stu.catagory,stu.sex);
        }
        fclose(fp);
} 
void mod() 
{ 
    FILE *fp; 
    int found=0; 
    char a[35]; 
    system("cls"); 
    printf("ENTER STUDENT ID:"); 
    fflush(stdin); 
    gets(a); 
    fp=fopen("student.txt","rb+"); 
    while(fread(&stu,sizeof(stu),1,fp)==1) 
        { 
            if(strcmp(a,stu.reg)==0) 
                { 
                    fflush(stdin); 
                    printf("\n\nNAME:"); 
                    scanf("%[^\n]",stu.name); 
                    printf("\nREGISTRATION NO:"); 
                    scanf("%s",stu.reg); 
                    fflush(stdin); 
                    printf("\nFATHER'S NAME:"); 
                    scanf("%[^\n]",stu.father_name); 
                    fflush(stdin); 
                    printf("\nMOTHER'S NAME:"); 
                    scanf("%[^\n]",stu.mother_name); 
                    fflush(stdin); 
                    printf("\nDEPARTMENT:"); 
                    scanf("%s",stu.department); 
                    fflush(stdin); 
                    printf("\nEMAIL ADDRESS:"); 
                    scanf("%s",stu.email_id); 
                    fflush(stdin); 
                    printf("\nPHONE NO:"); 
                    scanf("%ld",&stu.phone_no); 
                    fflush(stdin); 
                    printf("\nCATAGORY:"); 
                    scanf("%s",stu.catagory); 
                    fflush(stdin); 
                    printf("\nSEX:"); 
                    scanf("%s",stu.sex); 
                    fflush(stdin); 
                    fseek(fp,-sizeof(stu), SEEK_CUR); 
                    fwrite(&stu,sizeof(stu),1,fp); found=1; 
                    break; 
                } 
            } 
            if(!found) 
                printf("NO RECORD FOUND"); 
            fclose(fp); 
        } 
        void delete() 
        { 
            system("cls"); 
            printf("\t######## DELETE RECORD ########");

            char id[15];
            //int s;
            printf("\n\nENTER ID TO DELETE: ");
            fflush(stdin);
            gets(id);
            FILE *fp,*temp;
            if(strcmp(id,stu.reg)!=0)
                printf("\nREGISTRATION NUMBER IS NOT AVAILABLE");
            else
            {
                fp = fopen("student.txt","rb");
                temp = fopen("temp.txt", "wb");
                while(fread(&stu, sizeof(stu),1,fp))
                    { 
                        if(strcmp(id, stu.reg) != 0) 
                            { 
                                fwrite(&stu,sizeof(stu),1,temp); 
                            } 
                        } 
                        fclose(fp); 
                        fclose(temp); 
                        fp = fopen("student.txt","wb"); 
                        temp = fopen("temp.txt", "rb"); 
                        while(fread(&stu, sizeof(stu),1,temp)) 
                            fwrite(&stu, sizeof(stu),1,fp); 
                        remove("student.txt"); 
                        rename("temp.txt","record.txt"); 
                        printf("\nTHE RECORD IS SUCESSFULLY DELETED"); 
                        fclose(fp); 
                        fclose(temp); 
                    } 
                }
