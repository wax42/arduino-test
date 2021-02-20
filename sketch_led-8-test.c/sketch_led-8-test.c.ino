
    lc=LedControl(12,11,10,5);


void setup() { 

    for(int index=0;index<lc1.getDeviceCount();index++) {
        lc.shutdown(index,false); 
    } 
} 
