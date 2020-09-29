#define _GNU_SOURCE /* See feature_test_macros(7) */
#include <unistd.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //TODO: GET LOGIN/AUDIT UID, SECONDARY GROUPS
    char *uname = getlogin();
    uid_t ruid, euid, suid;
    struct passwd rpw, epw, spw, lpw;
    if (getresuid(&ruid, &euid, &suid) >= 0){
        rpw = *getpwuid(ruid);
        epw = *getpwuid(euid);
        spw = *getpwuid(suid);
        lpw = *getpwnam(uname);
    }
    else{
        printf("Failed Getting UID Information!\n");
    }
    gid_t rgid, egid, sgid;
    struct group rgp, egp, sgp;
    if (getresgid(&rgid, &egid, &sgid) >= 0){
        rgp = *getgrgid(rgid);
        egp = *getgrgid(egid);
        sgp = *getgrgid(sgid);
    }
    else{
        printf("Failed Getting GID Information!\n");
    }

    gid_t *secondary_groups;
    int group_num = getgroups(0, secondary_groups);
    if (group_num >= 0)
    {
        secondary_groups = (gid_t*) malloc(group_num * sizeof(gid_t));
        getgroups(group_num, secondary_groups);
    }
    else{
        printf("Failed Getting Secondary GID Information!\n");
    }

    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printf("Suggested Activity of Course Identifying Security Vulnerabilities in C/C++Programming\n");
            printf("Only one argument is used at a time\n");
            printf("–i: only the names corresponding to the UIDs and GIDs are displayed\n");
            printf("–n: only the numeric UIDs and GIDs are displayed\n");
            return 0;
        }

        if (strcmp(argv[1], "-i") == 0)
        {
            printf("Real UID: %s\n", rpw.pw_name);
            printf("Effective UID: %s\n", epw.pw_name);
            printf("Login UID: %s\n", uname);
            printf("Saved UID: %s\n", spw.pw_name);
            printf("Real GID: %s\n", rgp.gr_name);
            printf("Effective GID: %s\n", egp.gr_name);
            printf("Saved GID: %s\n", sgp.gr_name);
            printf("Secondary Groups: ");
            for (int i = 0; i < group_num; ++i)
            {
                struct group gp = *getgrgid(secondary_groups[i]);
                printf("%s", gp.gr_name);
                if (i < group_num - 1)
                {
                    printf(", ");
                }
            }
            printf("\n");
            return 0;
        }

        if (strcmp(argv[1], "-n") == 0)
        {
            printf("Real UID: %d\n", ruid);
            printf("Effective UID: %d\n", euid);
            printf("Login UID: %d\n", lpw.pw_uid);
            printf("Saved UID: %d\n", suid);
            printf("Real GID: %d\n", rgid);
            printf("Effective GID: %d\n", egid);
            printf("Saved GID: %d\n", sgid);
            printf("Secondary Groups: ");
            for (int i = 0; i < group_num; ++i)
            {
                struct group gp = *getgrgid(secondary_groups[i]);
                printf("%d", secondary_groups[i]);
                if (i < group_num - 1)
                {
                    printf(", ");
                }
            }
            printf("\n");
            return 0;
        }
    }
    printf("Real UID: %s(%d)\n", rpw.pw_name, ruid);
    printf("Effective UID: %s(%d)\n", epw.pw_name, euid);
    printf("Login UID: %s(%d)\n", uname, lpw.pw_uid);
    printf("Saved UID: %s(%d)\n", spw.pw_name, suid);
    printf("Real GID: %s(%d)\n", rgp.gr_name, rgid);
    printf("Effective GID: %s(%d)\n", egp.gr_name, egid);
    printf("Saved GID: %s(%d)\n", sgp.gr_name, sgid);
    printf("Secondary Groups: ");
    for (int i = 0; i < group_num; ++i)
    {
        struct group gp = *getgrgid(secondary_groups[i]);
        printf("%s(%d)", gp.gr_name, secondary_groups[i]);
        if (i < group_num - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}