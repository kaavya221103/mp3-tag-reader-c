#include "mp3_header.h"

void edit(struct MP3 *mp3, char * argv[])
{
    mp3->dup_mp3_fptr = fopen("temp.mp3", "w");

    if(mp3->dup_mp3_fptr == NULL)
    {
        printf("FILE DOES NOT EXIST\n");
        return;
    }
        
    mp3->org_mp3_fptr = fopen(mp3->mp3_filename, "r");

    char header[10];
    fread(header,10,1,mp3->org_mp3_fptr);
    fwrite(header,10,1,mp3->dup_mp3_fptr);

    int i=6;
    while(i)
    {
        char tag[5];
        fread(tag,4,1,mp3->org_mp3_fptr);
        fwrite(tag,4,1,mp3->dup_mp3_fptr);
        tag[4] = '\0'; 


        if(strcmp(mp3->given_tag, tag) != 0)
        {
            int frame_size;
            fread(&frame_size, sizeof(int), 1, mp3->org_mp3_fptr);
            
            fwrite(&frame_size, sizeof(int), 1,mp3->dup_mp3_fptr);
            toggle_endianess(mp3, &frame_size);

            char flag[3];
            fread(flag,3,1,mp3->org_mp3_fptr);
            fwrite(flag,3,1,mp3->dup_mp3_fptr);

            char ch;
            for(int i=0;i<frame_size-1;i++)
            {
                fread(&ch, 1,1,mp3->org_mp3_fptr);
                if(ch!=0)
                    fwrite(&ch,1,1,mp3->dup_mp3_fptr);
            }
        }
        //tag found
        else
        {
            int new_size = strlen(argv[3])+1;
            toggle_endianess(mp3, &new_size);
            fwrite(&new_size, sizeof(int), 1,mp3->dup_mp3_fptr);

            int frame_size;
            fread(&frame_size, sizeof(int), 1, mp3->org_mp3_fptr);
            toggle_endianess(mp3, &frame_size);


            char flag[3];
            fread(flag,3,1,mp3->org_mp3_fptr);
            fwrite(flag,3,1,mp3->dup_mp3_fptr);

            fseek(mp3->org_mp3_fptr, frame_size-1, SEEK_CUR);


          
            fwrite(argv[3],strlen(argv[3]),1,mp3->dup_mp3_fptr);
            break;
        }
        i--;
    }

    copy_remaining_data(mp3);

    remove("sample.mp3");
    rename("temp.mp3", "sample.mp3");
    print_edit(mp3, argv);

    fclose(mp3->dup_mp3_fptr);
    fclose(mp3->org_mp3_fptr);
}




    



