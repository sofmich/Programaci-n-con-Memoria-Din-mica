/*
 ============================================================================
 Name        : Tarea3_v2.c
 Author      : Momo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	unsigned short dd, mm, aa;
}Fecha;
typedef struct{
	unsigned short id_usuario;
	char nombre[15], apellido_p[15], apellido_m[15];
	Fecha fecha_u;
}Usuario;
typedef enum{true,false}bool;
Usuario capturarUsuario();
bool grabarUsuario(char ruta[55]);
bool existeIdCliente(char ruta[55], unsigned short id);
int posicionIdCliente(char ruta[55], unsigned short id);
void imprimirCliente(char ruta[55], unsigned short pos);
void imprimirClientes(char ruta[55]);
bool existenClientes(char ruta[55]);
int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	FILE *file;
	unsigned short opc = 0, aux_;
	Usuario aux;
	char ruta[] = "c:\\myDb\\Clientes.adm";
	file = fopen(ruta, "ab");
	fclose(file);
	do{
		printf("1 Registrar\n2 Existe id?\n3 Posicion id\n4 Imprimir todo\n");
		scanf("%hu", &opc);
		switch(opc){
		case 1:
			if(grabarUsuario(ruta)== true)printf("Usuario Registrado con éxito\n");
			break;
		case 2:
			if(existenClientes(ruta) == false) printf("No se encontraron registros en Clientes\n");
			else {
				printf("ID a buscar:");
				scanf("%hu", &aux_);
				if(existeIdCliente(ruta,aux_)== true) printf("Existe ID\n");
				else printf("No existe esta ID\n");
			}

			break;
		case 3:
			if(existenClientes(ruta) == false) printf("No se encontraron registros en Clientes\n");
			else{
				printf("ID posición a buscar:");
				scanf("%hu", &aux.id_usuario);
				if(existeIdCliente(ruta,aux.id_usuario)== true){
					aux_ = posicionIdCliente(ruta,aux.id_usuario);
					printf("El ID %hu está en la posición %hu\n", aux.id_usuario, aux_);
					imprimirCliente(ruta,aux_);
				}else printf("Esa ID no está registrada\n");
			}

			break;
		case 4:
			if(existenClientes(ruta) == false) printf("No se encontraron registros en Clientes\n");
			else imprimirClientes(ruta);
			break;
		}
	}while(opc != 0);

	return EXIT_SUCCESS;

}

Usuario capturarUsuario(){
	Usuario new;
	printf("Nombre: \t\t");
	scanf("%s", new.nombre);
	printf("Apellido paterno: \t");
	scanf("%s", new.apellido_p);
	printf("Apellido materno: \t");
	scanf("%s", new.apellido_m);
	printf("Fecha: dd/mm/aaaa");
	scanf("%hu/%hu/%hu\t",&new.fecha_u.dd,&new.fecha_u.mm,&new.fecha_u.aa);
	return new;
}
bool grabarUsuario(char ruta[55]){
	FILE *file;
	Usuario new = capturarUsuario(), aux;
	short len;
	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	if (len == 0) new.id_usuario = 1;
	else{
		fseek(file, ((len-1)*sizeof(Usuario)),SEEK_SET);
		fread(&aux,sizeof(Usuario),1,file);
		new.id_usuario = aux.id_usuario +1;
	}
	fclose(file);
	file = fopen(ruta,"ab+");
	if(file != NULL) {
		fwrite(&new,sizeof(Usuario),1,file);
		fclose(file);
		return true;
	}
	else return false;
}
bool existeIdCliente(char ruta[55], unsigned short id){
	short len, i, bandera = 0;
	Usuario aux;
	FILE *file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	for(i = 0; i < len; i++){
		fseek(file, (i*sizeof(Usuario)),SEEK_SET);
		fread(&aux,sizeof(Usuario),1,file);
		if(aux.id_usuario == id) bandera ++;
	}
	fclose(file);
	if(bandera != 0) return true;
	else return false;
}
int posicionIdCliente(char ruta[55], unsigned short id){
	FILE *file;
	Usuario aux;
	unsigned short len, i;
	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	for(i = 0; i< len; i++){
		fseek(file, (i*sizeof(Usuario)),SEEK_SET);
		fread(&aux,sizeof(Usuario),1,file);
		if(aux.id_usuario == id) {
			fclose(file);
			return i;
		}
	}
	fclose(file);
	return 0;
}
void imprimirCliente(char ruta[55], unsigned short pos){
	Usuario aux;
	FILE *file;
	file = fopen(ruta,"rb");
	fseek(file, (pos*sizeof(Usuario)),SEEK_SET);
	fread(&aux,sizeof(Usuario),1,file);
	printf("ID: %hu NOMBRE: %s %s %s FECHA: %hu/%hu/%hu\n",aux.id_usuario, aux.nombre, aux.apellido_p, aux.apellido_m, aux.fecha_u.dd, aux.fecha_u.mm, aux.fecha_u.aa);
	fclose(file);
}
void imprimirClientes(char ruta[55]){
	FILE *file;
	Usuario aux;
	unsigned short len, i;
	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	for(i = 0; i < len; i++){
		fseek(file, (i*sizeof(Usuario)),SEEK_SET);
		fread(&aux,sizeof(Usuario),1,file);
		printf("ID: %hu NOMBRE: %s %s %s FECHA: %hu/%hu/%hu\n",aux.id_usuario, aux.nombre, aux.apellido_p, aux.apellido_m, aux.fecha_u.dd, aux.fecha_u.mm, aux.fecha_u.aa);
	}

	fclose(file);
}
bool existenClientes(char ruta [55]){
	FILE * file = fopen(ruta,"rb");
	fseek(file,0,SEEK_END);
	unsigned short len = 0;
	len = ftell(file)/sizeof(Usuario);
	fclose(file);
	if (len > 0 )return true;
	else return false;
}
