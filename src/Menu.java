import javax.swing.*;
import java.awt.*;

class EJ2 {

    public static void main(String[] args) {
        new Sales();
    }
}

class Article {
    String name;
    double price;
    int quantity;

    Article() {
        name = JOptionPane.showInputDialog("Ingrese el nombre del producto");
        price = Double.parseDouble(
                JOptionPane.showInputDialog("Ingrese el precio del producto"));
        quantity = Integer.parseInt(
                JOptionPane.showInputDialog("Ingrese la cantidad del producto"));
    }

    String getArticleData() {
        return """
                Nombre: %s
                Precio: %.2f
                Cantidad: %d
                """.formatted(name, price, quantity);
    }
}

class Sales {
    Article[] articles;
    int index = 0;
    int totalSales = 0;

    Sales(int size) {

        articles = new Article[size];
        initWindow();
    }

    Sales() {

        articles = new Article[10];
        initWindow();
    }

    void initWindow() {

        Font font = new Font("Arial", Font.BOLD, 18);
        UIManager.put("OptionPane.messageFont", font);
        UIManager.put("OptionPane.buttonFont", font);
        UIManager.put("ComboBox.font", font);
        UIManager.put("TextField.font", font);
        menu();
    }

    void menu() {

        String[] options = {"Agregar Artículo", "Mostrar Artículos",
                "Buscar Artículo", "Eliminar Articulo",
                "¿Cuántos artículos más puedo agregar?",
                "¿Esta llena mi lista de artículos?", "Salir"};
        String selectedOption;
        String message;
        int emptySlots;
        do {
            selectedOption = (String) JOptionPane.showInputDialog(null,
                    "Seleccione una opción",
                    "Menú de Opciones",
                    JOptionPane.QUESTION_MESSAGE,
                    null, options, options[0]);
            if (selectedOption != null) {
                switch (selectedOption) {
                    case "Agregar Artículo" -> addArticle(new Article());
                    case "Mostrar Artículos" -> showSales();
                    case "Buscar Artículo" -> searchArticle();
                    case "Eliminar Articulo" -> deleteArticle();
                    case "¿Cuántos artículos más puedo agregar?" -> {

                        emptySlots = emptySlots();
                        message = emptySlots != 0 ? "Puede agregar %d artículos más".formatted(emptySlots)
                                : "No puede agregar más artículos";
                        JOptionPane.showMessageDialog(null, message);
                    }
                    case "¿Esta llena mi lista de artículos?" -> {

                        message = isFull() ? "La lista de artículos está llena"
                                : "La lista de artículos no está llena";
                        JOptionPane.showMessageDialog(null, message);
                    }
                }
            }
        } while (selectedOption != null && !selectedOption.equals("Salir"));
    }

    void deleteArticle() {
        String message = "Ingrese el nombre del artículo a eliminar";
        String articleName = JOptionPane.showInputDialog(null, message);
        boolean found = existsArticle(articleName);
        if (!found) {
            JOptionPane.showMessageDialog(null,
                    "Artículo no encontrado");
        }else{
            for (int i = 0; i < articles.length; i++) {
                if (articles[i] != null && articles[i].name.equals(articleName)) {
                    articles[i] = null;
                    JOptionPane.showMessageDialog(null,
                            "Artículo eliminado");
                    break;
                }
            }
        }
    }

    void searchArticle() {
        String message = "Ingrese el nombre del artículo a buscar";
        String articleName = JOptionPane.showInputDialog(null, message);
        boolean found = false;
        for (Article article : articles) {
            if (article != null && article.name.equals(articleName)) {
                JOptionPane.showMessageDialog(null,
                        article.getArticleData());
                found = true;
                break;
            }
        }
        if (!found) {
            JOptionPane.showMessageDialog(null, "Artículo no encontrado");
        }
    }

    boolean isFull() {

        return emptySlots() == 0;
    }

    int emptySlots() {
        int emptySlots = 0;
        for (Article article : articles) {
            if (article == null) {
                emptySlots++;
            }
        }
        return emptySlots;
    }

    boolean existsArticle(String articleName) {

        for (Article article : articles) {
            if (article != null && article.name.equals(articleName)) {
                return true;
            }
        }
        return false;
    }

    void addArticle(Article article) {

        boolean isAdded;
        if (isFull()) {
            JOptionPane.showMessageDialog(null,
                    "No puede agregar más artículos");
        } else {
            if (existsArticle(article.name)) {
                do{
                    JOptionPane.showMessageDialog(null, "El artículo ya existe");
                    article = new Article();
                    isAdded = !existsArticle(article.name);
                    if(isAdded){
                        for (int i = 0; i < articles.length; i++) {
                            if (articles[i] == null) {
                                articles[i] = article;
                                break;
                            }
                        }
                    }
                }while (!isAdded);
            } else {
                for (int i = 0; i < articles.length; i++) {
                    if (articles[i] == null) {
                        articles[i] = article;
                        break;
                    }
                }
            }
        }
    }

    void showSales() {
        StringBuilder articles = new StringBuilder();
        for (Article article : this.articles) {
            if (article == null) {
                break;
            }
            articles.append(article.getArticleData()).append("\n");
        }
        JOptionPane.showMessageDialog(null, articles);
    }
}