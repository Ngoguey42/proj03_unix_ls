/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:45:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 08:06:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

/* #include <unistd.h> */
/* #include <sys/types.h> */
#include <sys/stat.h>
#include <sys/xattr.h>

/*
opendir <sys/types.h> <dirent.h>
readdir <dirent.h>
closedir <dirent.h>
stat <sys/types.h> <sys/stat.h> <unistd.h>

lstat <sys/stat.h>
getpwuid <pwd.h>
getgrgid
listxattr
getxattr
time
ctime
readlink
perror
strerror
*/

/*
** 'main'
** First calls 'ls_save_args', might exit if invalid args or malloc fails.
*/

int		main(int ac, char **av)
{
	t_lsargs	*args;

	int i;//debug, print args
	ft_printf(":und:FT_LS{%Pd}:eou:(", ac);//debug, print args
	for (i = 0; i < ac ; i++)//debug, print args
		ft_printf("[%Pd=%Os]", i, av[i]);//debug, print args
	ft_putendl(")");//debug, print args

	args = ls_save_args(ac, av);
	if (AND_LF(LF_MASK))  //print with long format
		print_long_format(args);
//	else if (1) //print targets only  
//		print_target_format(args);
	else //print with small format
		print_small_format(args);
	ft_tabdel((void***)args->folders);
    ls_free_args(NULL);
	return (0);
}

// int	testtrucs(void)
// {

	// DIR				*dirptr;
	// struct dirent	*direntptr;
	// struct stat		*statptr;
	// int				statretint;

	// dirptr = opendir(".");

// /*
	// ft_printf("DIR : {sizeof=%u}\n", sizeof(DIR));
	// ft_printf("struct dirent : {sizeof=%u}\n", sizeof(struct dirent));
	// ft_printf("\t pad->d_ino    : %4tu size=%u\n", (void*)&direntptr->d_ino - (void*)direntptr, sizeof(direntptr->d_ino));
	// ft_printf("\t pad->d_reclen : %4tu size=%u\n", (void*)&direntptr->d_reclen - (void*)direntptr, sizeof(direntptr->d_reclen));
	// ft_printf("\t pad->d_type   : %4tu size=%u\n", (void*)&direntptr->d_type - (void*)direntptr, sizeof(direntptr->d_type));
	// ft_printf("\t pad->d_name   : %4tu size=%u\n", (void*)&direntptr->d_name - (void*)direntptr, sizeof(direntptr->d_name));
	
	// ft_printf("struct stat : {sizeof=%u}\n", sizeof(struct stat));
	// ft_printf("\t pad->st_dev    : %4tu size=%u\n", (void*)&statptr->st_dev - (void*)statptr, sizeof(statptr->st_dev));
	// ft_printf("\t pad->st_mode   : %4tu size=%u\n", (void*)&statptr->st_mode - (void*)statptr, sizeof(statptr->st_mode));
	// ft_printf("\t pad->st_nlink  : %4tu size=%u\n", (void*)&statptr->st_nlink - (void*)statptr, sizeof(statptr->st_nlink));
	// ft_printf("\t pad->st_ino    : %4tu size=%u\n", (void*)&statptr->st_ino - (void*)statptr, sizeof(statptr->st_ino));
	// ft_printf("\t pad->st_uid    : %4tu size=%u\n", (void*)&statptr->st_uid - (void*)statptr, sizeof(statptr->st_uid));
	// ft_printf("\t pad->st_gid    : %4tu size=%u\n", (void*)&statptr->st_gid - (void*)statptr, sizeof(statptr->st_gid));
	// ft_printf("\t pad->st_rdev   : %4tu size=%u\n", (void*)&statptr->st_rdev - (void*)statptr, sizeof(statptr->st_rdev));
	// ft_printf("\t pad->st_atime  : %4tu size=%u\n", (void*)&statptr->st_atime - (void*)statptr, sizeof(statptr->st_atime));
	// ft_printf("\t pad->st_mtime  : %4tu size=%u\n", (void*)&statptr->st_mtime - (void*)statptr, sizeof(statptr->st_mtime));
	// ft_printf("\t pad->st_ctime  : %4tu size=%u\n", (void*)&statptr->st_ctime - (void*)statptr, sizeof(statptr->st_ctime));
	// ft_printf("\t pad->st_size   : %4tu size=%u\n", (void*)&statptr->st_size - (void*)statptr, sizeof(statptr->st_size));
	// ft_printf("\t pad->st_blocks : %4tu size=%u\n", (void*)&statptr->st_blocks - (void*)statptr, sizeof(statptr->st_blocks));
	// ft_printf("\t pad->st_blksize: %4tu size=%u\n", (void*)&statptr->st_blksize - (void*)statptr, sizeof(statptr->st_blksize));

// */
// statptr = (struct stat*)malloc(sizeof(struct stat) * 1);
// struct passwd *passwdstruct;
// struct group *groupstruct;
// ssize_t listxattrret;
// size_t listxattrbufsize = 100;
// char *listxattrbuf = ft_strnew(listxattrbufsize);


	// while ((direntptr = readdir(dirptr)) != NULL)
	// {

// statretint = stat(direntptr->d_name, statptr);

	// ft_printf("{dirent d_ino(%8llu), d_reclen(%2hu), d_type(%M1hhu), d_name(%Ms)}\n", direntptr->d_ino, direntptr->d_reclen, direntptr->d_type, direntptr->d_name);
// ft_printf("dev(%u) mode(%M#hb) nlink(%hu) ino(%llu) uid(%Ru) gid(%Ru) rdev(%u) atime(%Qllu) mtime(%Qllu) ctime(%Qllu) size(%Qllu) blocks(%llu) blksize(%u)\n", (t_ui32)statptr->st_dev, (t_dbyte)statptr->st_mode, (t_dbyte)statptr->st_nlink, (t_ui64)statptr->st_ino, (t_ui32)statptr->st_uid, (t_ui32)statptr->st_gid, (t_ui32)statptr->st_rdev, (t_ui64)statptr->st_atime, (t_ui64)statptr->st_mtime, (t_ui64)statptr->st_ctime, (t_ui64)statptr->st_size, (t_ui64)statptr->st_blocks, (t_ui32)statptr->st_blksize);

// passwdstruct = getpwuid(statptr->st_uid);
// ft_printf("pw_name(%Rs) ", passwdstruct->pw_name);

// groupstruct = getgrgid(statptr->st_gid);
// ft_printf("gr_name(%RUs)", groupstruct->gr_name);


// listxattrret = getxattr("", direntptr->d_name, listxattrbuf, listxattrbufsize, 0, XATTR_NOFOLLOW);
// /* listxattrret = listxattr(direntptr->d_name, listxattrbuf, listxattrbufsize, XATTR_NOFOLLOW); */

// ft_printf("xattr ret[%d] name(%Ms)", listxattrret, listxattrbuf);

// ft_printf("\n\n");
	// }

// /*
// printf("lol%2u block\n", DT_BLK);
	// printf("lol%2u character device\n", DT_CHR);
	// printf("lol%2u dir\n", DT_DIR);
	// printf("lol%2u named pipe fifo\n", DT_FIFO);
	// printf("lol%2u symb link\n", DT_LNK);
	// printf("lol%2u regular\n", DT_REG);
	// printf("lol%2u unix domain socket\n", DT_SOCK);
	// printf("lol%2u unknown\n", DT_UNKNOWN);
// */

	// (void)dirptr;
	// (void)passwdstruct;
	// (void)statptr;
	// (void)direntptr;
	// (void)statretint;

	// return (0);
// }
