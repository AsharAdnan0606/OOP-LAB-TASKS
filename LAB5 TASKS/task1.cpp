#include<iostream>
using namespace std;

class Engine{
	public:
		void start(){
			cout<<"Engine Started"<<endl;
		}
		
		void stop(){
			cout<<"Engine Stopped"<<endl;
		}
		
		~Engine(){
			
		}
};


class Car{
		private: 
		   Engine engine;
				
		public:
			
			void startCar(){
				engine.start();
			}
						
			void stopCar(){
				engine.stop();
			}					
		
			~Car(){			
			}
};

int main(){
	
	Car car1;
	car1.startCar();
	car1.stopCar();
	
	
	return 0;
}
