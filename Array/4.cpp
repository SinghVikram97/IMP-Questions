Platforms for Buses/Trains
https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

int platformsNeeded(int arrival[], int departure[], int n) {
   
   sort(arrival,arrival+n);
   sort(departure,departure+n);
    
   int i=1,j=0;
   int maxPlatforms=1;
   int platforms=1;
   
   while(i<n && j<n){
       
       if(arrival[i]<=departure[j]){
           // Increase platforms
           platforms++;
           i++;
           maxPlatforms=max(maxPlatforms,platforms);
       }
       else{
           platforms--;
           j++;
       }
       
   }
    return maxPlatforms;   
}
