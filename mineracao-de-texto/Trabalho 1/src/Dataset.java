import javax.xml.parsers.DocumentBuilderFactory;

import java.util.Map;

import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;

public class Dataset {
	public void lerDataset(String arquivo) {
	    System.out.println("---------------------------------");
		System.out.println("Iniciando leitura do dataset.");
	    System.out.println("---------------------------------");
		try {
			Palavra palavra = new Palavra();
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			DocumentBuilder db = dbf.newDocumentBuilder();
			Document doc = db.parse(arquivo);
			doc.getDocumentElement().normalize();
			NodeList mensagem = doc.getElementsByTagName("message");
			
			for (int i = 0; i < mensagem.getLength(); i++) {
				Node node = mensagem.item(i);
				
				if (node.getNodeType() == Node.ELEMENT_NODE) {
					Element eElement = (Element) node;
					//String autor = eElement.getElementsByTagName("author").item(0).getTextContent();
					String msg = eElement.getElementsByTagName("text").item(0).getTextContent();
				    palavra.contarPalavras(msg);

					//System.out.println("\n---------------------------------");
					//System.out.println("Autor: " + autor);
					//System.out.println("Mensagem: " + msg);
				    //System.out.println("---------------------------------");

				}
			}
		    System.out.println("\n---------------------------------");
			System.out.println("Dataset lido com sucesso.");
		    System.out.println("---------------------------------");
		    palavra.imprimirPalavras();
		}

		catch (Exception e) {
			e.printStackTrace();
		}
	}
}