import java.util.Arrays;

public class Stat{
    public static int arr[] = {80, 72, 11, 25, 59, 82, 99};
    public static double sum;
    public static double avg;
    public static int minValue = arr[0];
    public static int maxValue = arr[0];
    public static double m =0;
    public static double num = 0;
            public static class Thread1 implements Runnable{
                @Override
                public void run() {
                    for(int i = 0; i<arr.length;i++){
                        sum = sum + arr[i];
                    }
                        avg = sum/arr.length;
                        System.out.println("The average value is: "+ avg);
                }
                    
                }


            public static class Thread2 implements Runnable{
                @Override
                public void run() {
                    for(int i=1;i<arr.length;i++){ 
                        if(arr[i] < minValue){ 
                          minValue = arr[i]; 
                        }
                    }
                    System.out.println("The minimum value is: "+ minValue);
            }
            public static class Thread3 implements Runnable{
                @Override
                public void run() {
                    for(int i=1;i<arr.length;i++){ 
                        if(arr[i] > maxValue){ 
                          maxValue = arr[i]; 
                        }
                    }
                    System.out.println("The minimum value is: "+ maxValue);
            }
            }
            public static class Thread4 implements Runnable{
                @Override
                public void run() {
                    Arrays.sort(arr);
                    if(arr.length%2==1){
                            m=arr[(arr.length+1)/2-1];
                        }
                        else
                        {
                            m=(arr[arr.length/2-1]+arr[arr.length/2])/2;
                        }
                System.out.println("The median value is: "+m);
            }
        }
        public static class Thread5 implements Runnable{

            @Override
            public void run() {
                for(int i=0;i<arr.length;i++ ){
                    num+= Math.pow((arr[i]-avg),2);
        
                }
                double sd = Math.sqrt(num/arr.length);
                System.out.println("The standard deviation value is: "+sd);

            }

        }

    public static void main(String[] args) throws InterruptedException{
        Runnable Thread1 = new Thread1();
        Runnable Thread2 = new Thread2();
        Runnable Thread3 = new Thread3();
        Runnable Thread4 = new Thread4();
        Runnable Thread5 = new Thread5();


        Thread t1 = new Thread(Thread1, "Thread 1");
        Thread t2 = new Thread(Thread2, "Thread 2");
        Thread t3 = new Thread(Thread3, "Thread 3");
        Thread t4 = new Thread(Thread4, "Thread 4");
        Thread t5 = new Thread(Thread5, "Thread 5");


        t1.start();
        t1.join();
        t2.start();
        t2.join();
        t3.start();
        t3.join();
        t4.start();
        t4.join();
        t5.start();
        t5.join();
        

        
    }
}
}
