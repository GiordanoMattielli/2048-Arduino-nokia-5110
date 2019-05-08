#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);

typedef struct matriz{
  int l , h , valor;
}Matriz;

Matriz matriz[4][4];

void up(){
  for(int i=0;i<4;i++){
    zero_up(i);
    for(int j=3;j>0;j--){
      if(matriz[i][j].valor == matriz[i][j-1].valor){
        matriz[i][j-1].valor *= 2;
        matriz[i][j].valor = 0;  
      }
    }
    zero_up(i);
  }
}
void zero_up(int i){
  int aux=0;
  for(int w = 0;w<4;w++){
    for(int j=0;j<4;j++){
      if(matriz[i][j].valor == 0){
        for(int k=j;k<3;k++){
          aux = matriz[i][k].valor;
          matriz[i][k].valor = matriz[i][k+1].valor;
          matriz[i][k+1].valor = aux;
        }
      }
    }
  }
}
void down(){
  for(int i=0;i<4;i++){
    zero_down(i);
    for(int j=0;j<3;j++){
      if(matriz[i][j].valor == matriz[i][j+1].valor){
        matriz[i][j+1].valor *= 2;
        matriz[i][j].valor = 0;  
      }
    }
    zero_down(i);
  }
}
void zero_down(int i){
  int aux=0;
  for(int w = 0;w<4;w++){
    for(int j=3;j>0;j--){
      if(matriz[i][j].valor == 0){
        for(int k=j;k>0;k--){
          aux = matriz[i][k].valor;
          matriz[i][k].valor = matriz[i][k-1].valor;
          matriz[i][k-1].valor = aux;
        }
      }
    }
  }
}
void right(){
  for(int j=0;j<4;j++){
    zero_right(j);
    for(int i=3;i>0;i--){
      if(matriz[i][j].valor == matriz[i-1][j].valor){
        matriz[i][j].valor *= 2;
        matriz[i-1][j].valor = 0;  
      }
    }
    zero_right(j);
  }
}
void zero_right(int j){
  int aux = 0;
  for(int w = 0;w<4;w++){
    for(int i = 3;i>0;i--){
      if(matriz[i][j].valor == 0){
        for(int k = i;k>0;k--){
          aux = matriz[k][j].valor;
          matriz[k][j].valor = matriz[k-1][j].valor;
          matriz[k-1][j].valor = aux;
        }
      }
    }
  }

}
void left(){
  for(int j=0;j<4;j++){
    zero_left(j);
    for(int i=0;i<3;i++){
      if(matriz[i][j].valor == matriz[i+1][j].valor){
        matriz[i][j].valor *= 2;
        matriz[i+1][j].valor = 0;  
      }
    }
    zero_left(j);
  }
}
void zero_left(int j){
  int aux = 0;
  for(int w = 0;w<4;w++){
    for(int i = 0;i<3;i++){
      if(matriz[i][j].valor == 0){
        for(int k = i;k<3;k++){
          aux = matriz[k][j].valor;
          matriz[k][j].valor = matriz[k+1][j].valor;
          matriz[k+1][j].valor = aux;
        }
      }
    }
  }

}


int vazio(int v[]){
  int out=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(matriz[i][j].valor == 0){
        v[out] = i*4+j;
        out++;
      }
    }
  }
  return out;
}

void jogo_velha(){
  for(int i = 0;i<84;i++)
    display.drawPixel(i, 11, BLACK);  
  for(int i = 0;i<84;i++)
    display.drawPixel(i, 23, BLACK);
  for(int i = 0;i<84;i++)
    display.drawPixel(i, 35, BLACK);

  for(int i = 0;i<48;i++)
    display.drawPixel(20, i, BLACK);  
  for(int i = 0;i<48;i++)
    display.drawPixel(41, i, BLACK);
  for(int i = 0;i<48;i++)
    display.drawPixel(63, i, BLACK);  
}
void imprimir_matriz(){
  for(int i=0;i<4;i++){
    for(int j = 0;j<4;j++){
      imprimir(matriz[i][j].valor,matriz[i][j].l,matriz[i][j].h); 
    }
  }
}

void imprimir(int valor,int l , int h){
  display.setTextSize(1);
  if(valor == 0)
    return;
  if(valor == 2){
    display.setCursor(8+l,2+h);
    display.write('2'); 
  }
  if(valor == 4){
    display.setCursor(8+l,2+h);
    display.write('4');    
  }
  if(valor == 8){
    display.setCursor(8+l,2+h);
    display.write('8');   
  }
  if(valor == 16){
    display.setCursor(4+l,2+h);
    display.write('1');
    display.write('6');    
  }
  if(valor == 32){
    display.setCursor(4+l,2+h);
    display.write('3');
    display.write('2');   
  }
  if(valor == 64){
    display.setCursor(4+l,2+h);
    display.write('6');
    display.write('4');   
  }
  if(valor == 128){
    display.setCursor(1+l,2+h);
    display.write('1');
    display.write('2');
    display.write('8');    
  }
  if(valor == 256){
    display.setCursor(1+l,2+h);
    display.write('2');
    display.write('5');
    display.write('6');   
  }
  if(valor == 512){
    display.setCursor(1+l,2+h);
    display.write('5');
    display.write('1');
    display.write('2');    
  }
  if(valor == 1024){
    display.setCursor(l+1,h+2);
    display.write('1');
    display.setCursor(l+6,h+2); 
    display.write('0');
    display.setCursor(10+l,2+h);
    display.write('2');
    display.setCursor(14+l,2+h);
    display.write('4');
  }
  if(valor == 2048){
    display.setCursor(l+1,h+2);
    display.write('2');
    display.setCursor(l+6,h+2); 
    display.write('0');
    display.setCursor(10+l,2+h);
    display.write('4');
    display.setCursor(14+l,2+h);
    display.write('8');  
  }
}
void iniciar_matriz(){
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      matriz[i][j].l = i*21 + 1;
      matriz[i][j].h = j*12 + 1;
      matriz[i][j].valor = 0;  
    }
  }
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      if(matriz[i][j].l == 1)
        matriz[i][j].l = 0;
      if(matriz[i][j].h == 1)  
        matriz[i][j].h = 0;   
    }
  }
}
void setup() {
  Serial.begin(9600);
  display.begin();
  display.setContrast(27);
  display.clearDisplay();
  display.display();
  display.clearDisplay();
  jogo_velha();
  display.setTextSize(1);
  display.setTextColor(BLACK);     
  display.display();
  display.clearDisplay();
  iniciar_matriz(); 
  randomSeed(666);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  for(int i =0;i<4;i++){
    for(int j=0;j<4;j++){
      matriz[i][j].valor =0;
    }
  }
}

void loop() {
  int v[16];
  int ret = 0;
  int out,aleatorio_1,aleatorio_2;
  display.clearDisplay();
  imprimir_matriz();
  jogo_velha();
  display.display();
  delay(100);
  out = vazio(v);
  if(out == 0){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.print("Voce\n") ;
    display.print("Perdeu\nLixo") ;    
    display.display();
    delay(2000);
  }else{
    if(out == 1){
       matriz[v[out-1] / 4][v[out-1]%4].valor += 2;
    }else{
      aleatorio_1 = random(0,out+1);
      //aleatorio_2 = random(0,out+1);
      matriz[v[aleatorio_1-1] / 4][v[aleatorio_1-1]%4].valor += 2;
     //matriz[v[aleatorio_2-1] / 4][v[aleatorio_2-1]%4].valor += 2;
    }
  }
  display.clearDisplay();
  imprimir_matriz();
  jogo_velha();
  display.display();
  //delay(500);
 while(ret == 0){
    delay(25);
    ret += botao_up();
    ret += botao_left();
    ret += botao_down();
    ret += botao_right();
 }
  
  display.clearDisplay();
  imprimir_matriz();
  jogo_velha();
  display.display();
  //delay(500); 
}
int botao_left(){
    int i = digitalRead(7);
     if (i == HIGH){
        left();
        while(i == HIGH){
          i=digitalRead(7);
          delay(5);
        }
        return 1;
     } 
     return 0;
}
int botao_down(){
    int i = digitalRead(6);
     if (i == HIGH){
        down();
        while(i == HIGH){
          i=digitalRead(6);
          delay(5);
        }
        return 1;
     } 
     return 0;
}
int botao_right(){
    int i = digitalRead(5);
     if (i == HIGH){
        right();
        while(digitalRead(5) == HIGH){
          delay(5);
        }
        return 1;
     } 
     return 0;
}
int botao_up(){
    int i = digitalRead(4);
     if (i == HIGH){
        up();
        while(digitalRead(4) == HIGH){
          delay(5);
        }
        return 1;
     } 
     return 0;
}
