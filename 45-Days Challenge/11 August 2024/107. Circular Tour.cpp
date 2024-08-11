class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
        int extraPetrol = 0;
        int index = 0;
        int count = 0;
       for( int i = 0; i< (2*n); i++ )
       {
           if( count == n )
           {
               break;
           }
           if( (extraPetrol + p[i%n].petrol) >= p[i%n].distance )
           {
               extraPetrol = (extraPetrol + p[i%n].petrol) - p[i%n].distance;
               count += 1;
           }
           else
           {
               count = 0;
               index = (i+1)%n;
               extraPetrol = 0;
           }
       }
       if( count == n )
       {
           return index;
       }
    return -1;
    }
};
