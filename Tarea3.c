/*
 ============================================================================
 Name        : Tarea3.c
 Author      : Momo (Sofía Michel Salazar Valdovinos)
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : myDataBaseSystem
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct{
	unsigned short dd, mm, aa;
}Fecha;
typedef struct{
	unsigned short id_usuario;
	char nombre[15], apellido_p[15], apellido_m[15];
	Fecha fecha_u;
}Usuario;
typedef struct{
	unsigned short id_cuenta, id_usuario;
	float saldo;
	Fecha fecha_c;
}Cuenta;
typedef struct{
	unsigned short id_transaccion, tipo_operacion, id_origen, id_destino;
	Fecha fecha_t;
	float monto;
}Transferencia;
void delay(int m);
Usuario capturarUsuario();
void grabarUsuario(FILE *file, char ruta[55]);
void buscarCliente(FILE *file, char ruta[55]);
void eliminarCliente(FILE *file, char ruta[55]);
void imprimirClientes(FILE *file, char ruta[55]);
/*


Cuenta capturarCuenta();
void grabarCuenta(FILE *file);
void buscarCuenta(unsigned short id);
void eliminarCuenta(unsigned short id);
void imprimirCuentas();
Transferencia capturarTransferencia(unsigned short opc);
void grabarTransferencia(FILE *file);
 */
int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	unsigned short opcion = 0, menu = 0, aux = 0;
	char ruta[40], ruta_mydb[55], ruta_clientes[55],ruta_tran[55], ruta_cuentas[55];
	FILE *f_clientes, *f_cuentas, *f_tran, *f_mydb;
	printf("<<Sistema MyDB>>\n");
	printf("Bienvenido al sistema. Por favor especifica la ruta de acceso a tus archivos.\n");
	printf("Ejemplo: c:\\\\carpeta\\\\:\t");
	scanf("%s",ruta);
	strcpy(ruta_mydb, ruta);
	strcpy(ruta_clientes, ruta);
	strcpy(ruta_tran, ruta);
	strcpy(ruta_cuentas, ruta);
	strcat(ruta_mydb,"mydb.sys");
	strcat(ruta_clientes,"clientes.dat");
	strcat(ruta_tran,"transacciones.dat");
	strcat(ruta_cuentas,"cuentas.dat");
	f_mydb = fopen(ruta_mydb,"rb+");
	f_clientes = fopen(ruta_clientes, "rb+");
	f_cuentas = fopen(ruta_cuentas, "rb+");
	f_tran = fopen(ruta_tran, "rb+");
	if(f_mydb == NULL || f_clientes == NULL || f_cuentas == NULL || f_tran == NULL) {
		printf("Parece que tenemos problemas...\nVerificaremos que los archivos existan.\n");
		//printf("Preparando archivos en ruta:\t%s\n", ruta);
		f_mydb = fopen(ruta_mydb,"wb+");
		f_clientes = fopen(ruta_clientes, "wb+");
		f_cuentas = fopen(ruta_cuentas, "wb+");
		f_tran = fopen(ruta_tran, "wb+");
		printf("Archivos listos. Bienvenido.\n");
	}else{
		f_mydb = fopen(ruta_mydb,"wb+");
		f_clientes = fopen(ruta_clientes, "wb+");
		f_cuentas = fopen(ruta_cuentas, "wb+");
		f_tran = fopen(ruta_tran, "wb+");
		printf("Preparando archivos en ruta:\t%s\n", ruta);
		printf("Archivos listos. Bienvenido.\n");
	}
	fclose(f_clientes);
	fclose(f_cuentas);
	fclose(f_tran);
	fwrite(ruta_mydb,sizeof(char),sizeof(ruta_mydb),f_mydb);
	/*char buffer[40];
	fscanf(f_mydb,"%s",buffer);
	printf("%s", buffer);*/
	fclose(f_mydb);
	//printf("%s", ruta_mydb);
	/*while(*p != '\0') {
		len ++;
		p++;
	}
	printf("Cantidad de caracteres en %s : %hu\n", ruta, len);

	while(*p != '\0') {
			len ++;
			p++;
		}
	printf("Cantidad de caracteres en %s : %hu\n", ruta, len);
	 */

	do{
		delay(1);
		system("cls");
		printf("<<Sistema MyDB>>\n");
		printf("1.Clientes\n2.Cuentas\n3.Transacciones\n4.Salir\n");
		scanf("%hu",&opcion);
		system("cls");
		delay(1);
		switch(opcion){
		case 1:
			printf("-->Clientes<--\n");
			printf("[1]Nuevo Cliente\n[2]Buscar Cliente\n[3]Eliminar Cliente\n[4]Imprimir Clientes\n");
			scanf("%hu",&menu);
			system("cls");
			delay(1);
			switch(menu){
			case 1:
				printf("=REGISTRO DE USUARIOS=\n");
				grabarUsuario(f_clientes, ruta_clientes);
				break;
			case 2:
				printf("=BÚSQUEDA DE CLIENTE=\n");

				buscarCliente(f_clientes,ruta_clientes);
				break;
			case 3:
				printf("=ELIMINAR CLIENTE=\n");

				eliminarCliente(f_clientes, ruta_clientes);
				break;
			case 4:
				printf("=IMPRIMIR CLIENTES=\n");
				imprimirClientes(f_clientes, ruta_clientes);
				break;
			}
			break;
			case 2:
				printf("-->Cuentas<--\n");
				printf("[1]Nueva Cuenta\n[2]Buscar Cuenta\n[3]Eliminar Cuenta\n[4]Imprimir Cuentas\n");
				scanf("%hu",&menu);
				system("cls");
				switch(menu){
				case 1:
					printf("=CREAR CUENTA=\n");
					//grabarCuenta(f_cuentas);
					break;
				case 2:
					printf("=BUSCAR CUENTA=\n");
					printf("ID:\t");
					scanf("%hu",&aux);
					//buscarCuenta(aux);
					break;
				case 3:
					printf("=ELIMINAR CUENTA=\n");
					printf("ID:\t");
					scanf("%hu",&aux);
					//eliminarCuenta(aux);
					break;
				case 4:
					printf("=IMPRIMIR CUENTAS=\n");
					//imprimirCuentas();
					break;
				}
				break;
				case 3:
					printf("-->Transacciones<--\n");
					printf("[1]Depositar\n[2]Retirar\n[3]Transferir\n");
					scanf("%hu",&menu);
					system("cls");
					switch(menu){
					case 1:
						printf("=DEPOSITAR=\n");
						//capturarTransferencia(1);
						break;
					case 2:
						printf("=RETIRAR=\n");
						printf("ID:\t");
						scanf("%hu",&aux);
						//capturarTransferencia(2);
						break;
					case 3:
						printf("=TRANSFERIR=\n");
						printf("ID:\t");
						scanf("%hu",&aux);
						//capturarTransferencia(3);
						break;
					}
					break;
					case 4:
						printf("Saliendo del sistema...\n");
						return -1;
		}
		system("cls");

	}while(opcion >= 1 && opcion <=4);
	printf("Has salido del sistema con éxito.");
	return EXIT_SUCCESS;
}
Usuario capturarUsuario(){
	Usuario nuevo;
	fflush(stdin);
	printf("Nombre:\t");
	scanf("%s",nuevo.nombre);
	//fgets(nuevo.nombre, 15, stdin);
	printf("Apellido Paterno:");
	scanf("%s",nuevo.apellido_p);
	fflush(stdin);
	//fgets(nuevo.apellido_p, 15, stdin);
	printf("Apellido Materno:");
	scanf("%s",nuevo.apellido_m);
	fflush(stdin);
	//fgets(nuevo.apellido_m, 15, stdin);
	printf("Fecha de Nacimiento: dd/mm/aaaa:");
	fflush(stdin);
	scanf("%hu/%hu/%hu",&nuevo.fecha_u.dd, &nuevo.fecha_u.mm, &nuevo.fecha_u.aa);
	return nuevo;
}
void grabarUsuario(FILE *file, char ruta[55]){
	Usuario nuevo, aux;
	nuevo = capturarUsuario();
	unsigned short len;
	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	if (len > 0){
		fseek(file, ((len-1)*sizeof(Usuario)),SEEK_SET);
		fread(&aux,sizeof(Usuario),1,file);
		//printf("%s\n",aux.nombre);
		nuevo.id_usuario = aux.id_usuario +1;
	} else nuevo.id_usuario = 1;
	fclose(file);

	file = fopen(ruta,"ab");
	if(file != NULL) {
		fwrite(&nuevo,sizeof(Usuario),1,file);
		printf("Grabado éxitosamente.\n");
	}
	fclose(file);
}
void buscarCliente(FILE *file, char ruta[55]){
	Usuario aux;
	unsigned short len;
	unsigned short id;

	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	if(len > 0){
		printf("ID:\t");
		scanf("%hu",&id);
		for(int i = 0; i < len; i++){
			fseek(file, (i*sizeof(Usuario)),SEEK_SET);
			fread(&aux,sizeof(Usuario),1,file);
			if(aux.id_usuario == id) printf("%d\t%s\t%s\t%s\t%02d/%02d/%04d\n ",aux.id_usuario, aux.nombre, aux.apellido_p, aux.apellido_m, aux.fecha_u.dd, aux.fecha_u.mm, aux.fecha_u.aa);
		}
	} else printf("No se encontraron registros. \n");
	/*while(!feof(file)){
		fread(&aux,sizeof(Usuario),1,file);
		if(aux.id_usuario == id){
			printf("%d\t%s\t%s\t%s\t%02d/%02d/%04d\n ",aux.id_usuario, aux.nombre, aux.apellido_p, aux.apellido_m, aux.fecha_u.dd, aux.fecha_u.mm, aux.fecha_u.aa);
		}
	}*/
	fclose(file);
}
void eliminarCliente(FILE *file, char ruta[55]){

	unsigned short len, index;
	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	fclose(file);
	unsigned short id, i;
	if(len > 0){
		printf("ID:\t");
		scanf("%hu",&id);
		Usuario *p_array = (Usuario*)malloc(sizeof(Usuario)*len);
		file = fopen(ruta,"rb");
		for(i = 0; i < len; i++){
			fread((p_array+i),sizeof(Usuario),1,file);
			if((p_array+i)->id_usuario == id) index = i;
		}
		fclose(file);
		file = fopen(ruta,"wb");
		if(index == len-1){
			for(i = 0; i < len ; i++){
				if(i!= index) fwrite((p_array+i),sizeof(Usuario),1,file);
			}
		}
		else if(index == 0){
			for(i = 0; i < len ; i++){
				if(i!=0)fwrite((p_array+i),sizeof(Usuario),1,file);
			}
		}
		else{
			for(i = 0; i < len ; i++){
				if(i != index) fwrite((p_array+i),sizeof(Usuario),1,file);
			}


		}
		fclose(file);
		/*for(i = index; i < len-1; i++){
			//printf("%d\t%s\t%s\t%s\t%02d/%02d/%04d\n ",(p_array+i)->id_usuario, (p_array+i)->nombre, (p_array+i)->apellido_p, (p_array+i)->apellido_m, (p_array+i)->fecha_u.dd, (p_array+i)->fecha_u.mm, (p_array+i)->fecha_u.aa);
			(p_array+i)->id_usuario = (p_array+i+1)->id_usuario;
			strcpy((p_array+i)->nombre,(p_array+i+1)->nombre);
			strcpy((p_array+i)->apellido_p,(p_array+i+1)->apellido_p);
			strcpy((p_array+i)->apellido_m,(p_array+i+1)->apellido_m);
			(p_array+i)->fecha_u.dd = (p_array+i+1)->fecha_u.dd;
			(p_array+i)->fecha_u.mm= (p_array+i+1)->fecha_u.mm;
			(p_array+i)->fecha_u.aa = (p_array+i+1)->fecha_u.aa;
			//printf("%d\t%s\t%s\t%s\t%02d/%02d/%04d\n ",(p_array+i)->id_usuario, (p_array+i)->nombre, (p_array+i)->apellido_p, (p_array+i)->apellido_m, (p_array+i)->fecha_u.dd, (p_array+i)->fecha_u.mm, (p_array+i)->fecha_u.aa);
		}*/
		imprimirClientes(file,ruta);
	}else printf("No se encontraron registros. \n");
}
void imprimirClientes(FILE *file, char ruta[55]){
	int len;
	Usuario aux;
	file = fopen(ruta,"rb");
	fseek(file, 0, SEEK_END);
	len = ftell(file) / sizeof(Usuario);
	//printf("Usuarios grabados: %d\n", len);
	if(len>0){
		for(int i = 0; i < len; i++){
			fseek(file, (i*sizeof(Usuario)),SEEK_SET);
			fread(&aux,sizeof(Usuario),1,file);
			printf("%d\t%s\t%s\t%s\t%02d/%02d/%04d\n ",aux.id_usuario, aux.nombre, aux.apellido_p, aux.apellido_m, aux.fecha_u.dd, aux.fecha_u.mm, aux.fecha_u.aa);
		}
	}else  printf("No se encontraron registros. \n");
	/*(!feof(file)){
		fread(&aux,sizeof(Usuario),1,file);
		printf("%d\t%s\t%s\t%s\t%02d/%02d/%04d\n ",aux.id_usuario, aux.nombre, aux.apellido_p, aux.apellido_m, aux.fecha_u.dd, aux.fecha_u.mm, aux.fecha_u.aa);

	}*/
	fclose(file);
}
void delay(int m)
{
	long pause;
	clock_t now,then;
	pause = m*(CLOCKS_PER_SEC);
	now = then = clock();
	while( (now-then) < pause )
		now = clock();
}
/*

Cuenta capturarCuenta(){

}
void grabarCuenta(FILE *file){

}
void buscarCuenta(unsigned short id){

}
void eliminarCuenta(unsigned short id){

}
void imprimirCuentas(){

}
Transferencia capturarTransferencia(unsigned short opc){

}
void grabarTransferencia(FILE *file){

}

 */
