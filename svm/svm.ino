
float dado,p,r,t=0;
int i=0;


float interceptsvm=1.53657665;

float svmclasfr[60]={-0.164439,-0.025668,0.036732,-0.452821,-0.423960,0.104029,0.010371,0.097651,-0.593929,-0.655658,-1.464572,-1.779258,-0.649999,0.672634,0.563192,0.644728,
0.154206,0.087459,-0.563681,-0.605735,-0.524190,-0.361442,-0.202717,-0.334983,-0.069219,0.443480,0.287569,-0.197278,-0.094463,-0.494586,0.660724,-0.119480,-0.135146,-0.076676,
0.510124,1.288181,0.627821,-0.432850,-0.414678,0.379195,-0.018713,-0.601434,-0.862729,-1.160702,-1.125702,-0.890707,-0.596614,-0.286881,-0.263217,0.013230,-0.034782,-0.038928,
-0.028410,-0.053492,0.004622,0.008699,0.016459,-0.025350,-0.037620,-0.029474};

float sensor [60];

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0){i=0;}
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
   // r+=sensor[j]*svmclasfr[j];
   r+=sensor[j]*modelo[j];
    }
    
   p= r+interceptsvm;  //SVM Kernel linear  se p<-1 classe=0   se p>+1 classe=1

uint32_t ts2 = micros();
  
 Serial.print("p= ");
 Serial.println(p,6);
 Serial.print("Demorei:");
 Serial.print(ts2-ts1);
 Serial.println(" microssegundos");

 
 }


  
  }
