import java.util.*;
import java.util.Map.Entry;

public class Palavra {
	private static Map<String, Integer> contadorDataset = new HashMap<String, Integer>();
	private static Map<String, Integer> contadorLexico = new HashMap<String, Integer>();
	private static Map<String, String> palavrasLexico = new HashMap<String, String>();

	public Map<String, Integer> contarPalavras(String msg) {
		String[] palavras = msg.split("\\s+");
		String lexicoPath = "src/NetSpeak.csv";
		Lexico lexico = new Lexico();
		palavrasLexico = lexico.lerLexico(lexicoPath);
		
		for (int i = 0; i < palavras.length; i++) {
			palavras[i] = palavras[i].toLowerCase();
			palavras[i] = palavras[i].replaceAll("[^a-zA-Z]+","");
			//palavras[i] = palavras[i].strip();
			if (palavras[i] != "" && palavras[i] != "nan")
				contadorDataset.put(palavras[i], contadorDataset.getOrDefault(palavras[i], 0) + 1);
			if(palavrasLexico.containsKey(palavras[i])) {
				contadorLexico.put(palavras[i], contadorLexico.getOrDefault(palavras[i], 0) + 1);
			}
		}
		return contadorDataset;
	}

	public void imprimirPalavras(){
		ArrayList<Integer> list = new ArrayList<>();
	    LinkedHashMap<String, Integer> datasetOrdenado = new LinkedHashMap<>();
		for (Map.Entry<String, Integer> entry : contadorDataset.entrySet()) {
	           list.add(entry.getValue());
	    }
	    Collections.sort(list, Collections.reverseOrder()); 
	    for (int num : list) {
	    	for (Entry<String, Integer> entry : contadorDataset.entrySet()) {
	    		if (entry.getValue().equals(num)) {
	    			datasetOrdenado.put(entry.getKey(), num);
	            }
	        }
	    }
	    
	    int qntdPalavras = 0;
	    System.out.println("\n---------------------------------");
		System.out.println("As 100 palavras do dataset mais utilizadas:");
	    System.out.println("---------------------------------\n");
	    //contadorOrdenado.entrySet().forEach((entry) -> System.out.println(entry.getKey() + " : " + entry.getValue()));
	    for (Map.Entry<String, Integer> entry : datasetOrdenado.entrySet()) {
            if (qntdPalavras < 100) {
                System.out.println(qntdPalavras+1 +" - Palavra: " + entry.getKey() + " | Ocorrências: " + entry.getValue());
                qntdPalavras++;
            } else {
                break;
            }
        }
	    
		ArrayList<Integer> list2 = new ArrayList<>();
	    LinkedHashMap<String, Integer> lexicoOrdenado = new LinkedHashMap<>();
		for (Map.Entry<String, Integer> entry : contadorLexico.entrySet()) {
	           list2.add(entry.getValue());
	    }
	    Collections.sort(list2, Collections.reverseOrder()); 
	    for (int num : list2) {
	    	for (Entry<String, Integer> entry : contadorLexico.entrySet()) {
	    		if (entry.getValue().equals(num)) {
	                lexicoOrdenado.put(entry.getKey(), num);
	            }
	        }
	    }

	    System.out.println("\n---------------------------------");
		System.out.println("As 20 palavras do léxico mais utilizadas:");
	    System.out.println("---------------------------------\n");
	    qntdPalavras = 0;
	    for (Map.Entry<String, Integer> entry : lexicoOrdenado.entrySet()) {
            if (qntdPalavras < 20) {
                System.out.println(qntdPalavras+1 +" - Palavra: " + entry.getKey() + " | Ocorrências: " + entry.getValue());
                qntdPalavras++;
            } else {
                break;
            }
        }
	}
}