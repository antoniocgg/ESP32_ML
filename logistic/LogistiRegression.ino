

int i=0;

float intercept= 0.94204354 ; // valor obtido do modelo. em python: print(class_logistic.intercept_,class_logistic.coef_)

float p=0;
float r,t,p,dado=0;

float modelo [60]={-0.331842,-0.218286,-0.068279,-0.643945,-0.701883,-0.125764,0.176500,-0.034293,-0.935264,-1.019103,-1.869585,-1.771572,-0.480439,0.553921,0.595598,0.636730,
0.499040,0.383028,-0.508547,-0.605314,-0.556495,-0.474525,-0.223114,-0.597005,0.238243,0.587069,0.000125,-0.291708,-0.052808,-0.281494,1.123891,-0.262425,-0.217632,0.423220,
0.633498,1.327743,0.984247,-0.252632,-0.409646,0.759118,-0.064119,-0.619781,-1.401445,-1.425113,-1.652816,-1.279313,-0.723812,-0.712210,-0.545362,-0.032281,-0.137193,
-0.116152,-0.059307,-0.104200,-0.002956,-0.016121,0.011830,-0.071588,-0.094703,-0.047775};

float sensor [60];

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0){i=0;}     //Envia os 60 valores via serial. Para enviar, abra o Monitor Serial, copie os dados da amostra 
                                        //(todos os 60, texto, separados por vírgula) cole e envie para o ESP32.
dado= Serial.parseFloat();
if(dado>=0&&i<60){
   sensor[i]=dado;   
   i++;
  }

 if(i==60){  
uint32_t ts1 = micros(); // mede o tempo
  
  i=0;
  r=0;
  p=0;
  //multiplica as entradas do sensor pelos coeficientes aprendidos na criação do modelo.
  for(int j=0;j<60;j++){
   r+=sensor[j]*modelo[j];
    }
    
  p= 1/(1+exp(-(intercept + r))) ;  //regressão logística

uint32_t ts2 = micros();  //calcula o tempo que levou.
  
 Serial.print("p= ");
 Serial.println(p,6);
 Serial.print("Demorei:");
 Serial.print(ts2-ts1);
 Serial.println(" microssegundos");

 
 }


  
  }
