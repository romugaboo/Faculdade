import java.util.*;
import java.io.*;

public class Lexico {
	Map<String, String> palavrasLexico = new HashMap<String, String>();
	
	public Map<String, String> lerLexico(String arquivo){
		Scanner sc;
		try {
			sc = new Scanner(new File(arquivo));
			sc.useDelimiter(",");
			while (sc.hasNext()) {  
				String palavras[] = sc.nextLine().split(";");
				palavrasLexico.put(palavras[0], palavras[1]);
				//System.out.print("Termo: " + palavras[0] + " | Tradução: " + palavras[1] + "\n");
			}   
			sc.close();
		}
		
		catch (FileNotFoundException e) {
			e.printStackTrace();
		} 
		return palavrasLexico;
	}
}