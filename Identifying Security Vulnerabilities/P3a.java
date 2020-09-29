i​mport java.io.Console;
i​mport java.security.*;
i​mport java.io.*;
i​mport javax.xml.bind.DatatypeConverter;
i​mport java.util.*;

class Lab4Class {
    public static void main(String[] args) {

	Console console = System.console();

	if( console == null ) {
	     System.out.print("Console unavailable");
	    return;
	}

	SecureRandom salt = new SecureRandom();
	int salt_byte_len = 32;
	byte salt_bytes[] = new byte[salt_byte_len];
	salt.nextBytes(salt_bytes);
	String sl = DatatypeConverter.printHexBinary(salt_bytes);
    console.printf("Here is your salt: %s\n", sl); 
   }

}
