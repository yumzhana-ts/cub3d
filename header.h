#ifndef MY_HEADER_H
#define MY_HEADER_H

int	checkextension(char *name);
int	fd_error(char *s);
int	parsing(int argc, char **argv);
int	read_map(char *argv, t_data *m);
int main(int argc, char **argv);

#endif // MY_HEADER_H

// Additional prototypes
int	checkextension(char *name)
;
int	fd_error(char *s)
;
int	parsing(int argc, char **argv)
;
int	read_map(char *argv, t_data *m)
;
int main(int argc, char **argv) 
;
