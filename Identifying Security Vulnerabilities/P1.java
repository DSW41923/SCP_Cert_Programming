import java.io.Console;

class Lab4Class
{ 
    public static void main(String args[])  
    { 
        //Obtaining a reference to the console. 
        Console console = System.console(); 
        if( console == null ) {
            System.out.print("Console unavailable");
            return;
        }
          
        // Read a string and then display it. 
        String password = console.readLine("Enter password: "); 
        console.printf("Here is your password: %s\n", password); 
    } 
} 
