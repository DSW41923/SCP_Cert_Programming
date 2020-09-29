import java.io.Console;
i​mport java.security.MessageDigest;
i​mport javax.xml.bind.DatatypeConverter;
i​mport java.security.*;

class Lab4Class
{ 
    public static void main(String args[])  
    { 
        String pwd; 
          
        //Obtaining a reference to the console. 
        Console console = System.console(); 

        if( console == null ) {
            System.out.print("Console unavailable");
            return;
        }
          
        // Read a string and then display it. 
        pwd = console.readLine("Enter password: "); 
        console.printf("Here is your password: %s\n", pwd); 
        try{
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(pwd.getBytes());
            byte[] digest = md.digest();
            String hash_pwd = DatatypeConverter.printHexBinary(digest);
            console.printf("Here is your hashed password: %s\n", hash_pwd.toUpperCase()); 
         }
        catch(NoSuchAlgorithmException e){
            System.out.println(e);
        }

    } 
} 