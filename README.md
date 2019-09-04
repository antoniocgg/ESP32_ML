# ESP32_ML
Implementando modelos de ML no ESP32, usando a IDE do Arduino

Uma prova de conceito para testar a utilização de modelos de ML em microcontroladores
Os modelos são criados em Python com o pacote scikit-learn e os coeficientes copiados no código C do microcontrolador

Segui o seguinte roteiro, utilizando o dataset Rocks vs Mines, amplamente disponível na internet.

- Criação de modelos de classificação (Regressão Logística, SVM e Redes Neurais). Verifique os notebooks
- Os modelos foram refinados para atender as expectativas de funcionamento com base no dataset Rocks vs Mines. Eliminados os falsos positivos
- Em seguida criei um algoritmo "from scratch" para comparar com as predições feitas pelo scikit-learn
- Após verificar o funcionamento, os coeficientes foram exportados em um arquivo CSV e colados no código C do Arduino.
- Implementei o algoritmo de predição na linguagem C do Arduino e testei enviando dados através do Monitor Serial. Simplesmente copiando a amostra e colando. (valores separados por vírgula)

A implementação de modelos de inteligência Artificial no ESP32 é plenamente possível e tem bom desempenho, atentando-se
às limitações de memória RAM do dispositivo que mostrou-se adequada à datasets < 100 variáveis. 






![alt text](https://github.com/antoniocgg/ESP32_ML/blob/master/ESP32.jpg)
