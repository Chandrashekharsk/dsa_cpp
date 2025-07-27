import java.util.*;

enum TokenType {
    KEYWORD, IDENTIFIER, INTEGER, FLOAT, OPERATOR, SEPARATOR, UNKNOWN
}

class Token {
    TokenType type;
    String lexeme;
    int line;
    int column;

    Token(TokenType type, String lexeme, int line, int column) {
        this.type = type;
        this.lexeme = lexeme;
        this.line = line;
        this.column = column;
    }
}

public class Toknization {

    static final Set<String> keywords = new HashSet<>(Arrays.asList(
        "if", "else", "while", "for", "int", "float", "char",
        "return", "void", "main", "cout", "cin"
    ));

    static boolean isKeyword(String s) {
        return keywords.contains(s);
    }

    static boolean isOperator(char c) {
        return "+-*/%=<>!&|".indexOf(c) != -1;
    }

    static boolean isSeparator(char c) {
        return "();{}[],[]".indexOf(c) != -1;
    }

    static String getTokenTypeString(TokenType type) {
        return type.name();
    }

    static List<Token> tokenize(String sourceCode) {
        List<Token> tokens = new ArrayList<>();
        int line = 1, col = 1;

        for (int i = 0; i < sourceCode.length(); i++) {
            char ch = sourceCode.charAt(i);

            if (ch == '\n') {
                line++;
                col = 1;
                continue;
            }

            if (Character.isWhitespace(ch)) {
                col++;
                continue;
            }

            // Operators
            if (isOperator(ch)) {
                String op = String.valueOf(ch);
                if (i + 1 < sourceCode.length()) {
                    char next = sourceCode.charAt(i + 1);
                    if ((ch == '=' && next == '=') || (ch == '>' && next == '=') ||
                        (ch == '<' && next == '=') || (ch == '!' && next == '=') ||
                        (ch == '&' && next == '&') || (ch == '|' && next == '|')) {
                        op += next;
                        i++;
                    }
                }
                tokens.add(new Token(TokenType.OPERATOR, op, line, col));
                col += op.length();
                continue;
            }

            // Separators
            if (isSeparator(ch)) {
                tokens.add(new Token(TokenType.SEPARATOR, String.valueOf(ch), line, col));
                col++;
                continue;
            }

            // Identifiers / Keywords
            if (Character.isLetter(ch) || ch == '_') {
                StringBuilder sb = new StringBuilder();
                int startCol = col;
                while (i < sourceCode.length() && (Character.isLetterOrDigit(sourceCode.charAt(i)) || sourceCode.charAt(i) == '_')) {
                    sb.append(sourceCode.charAt(i));
                    i++;
                    col++;
                }
                i--; // Because loop will increment
                String lexeme = sb.toString();
                TokenType type = isKeyword(lexeme) ? TokenType.KEYWORD : TokenType.IDENTIFIER;
                tokens.add(new Token(type, lexeme, line, startCol));
                continue;
            }

            // Numbers (Int or Float)
            if (Character.isDigit(ch)) {
                StringBuilder sb = new StringBuilder();
                int startCol = col;
                boolean isFloat = false;

                while (i < sourceCode.length() && Character.isDigit(sourceCode.charAt(i))) {
                    sb.append(sourceCode.charAt(i));
                    i++;
                    col++;
                }

                if (i < sourceCode.length() && sourceCode.charAt(i) == '.') {
                    isFloat = true;
                    sb.append(sourceCode.charAt(i));
                    i++;
                    col++;
                    while (i < sourceCode.length() && Character.isDigit(sourceCode.charAt(i))) {
                        sb.append(sourceCode.charAt(i));
                        i++;
                        col++;
                    }
                }

                i--; // Adjust for loop
                String lexeme = sb.toString();
                tokens.add(new Token(isFloat ? TokenType.FLOAT : TokenType.INTEGER, lexeme, line, startCol));
                continue;
            }

            // Unknown Token
            tokens.add(new Token(TokenType.UNKNOWN, String.valueOf(ch), line, col));
            col++;
        }

        return tokens;
    }

    public static void main(String[] args) {
        String sourceCode = """
        int main() {
            int x = 10;
            float y = 20.5;
            if (x > 5 && y != 10.0) {
                cout << "Hello World!";
            }
            return 0;
        }
        """;

        System.out.println("Source Code:\n" + sourceCode);
        List<Token> tokens = tokenize(sourceCode);

        System.out.println("\nTokens:");
        System.out.println("--------------------------------------------------");
        System.out.printf("%-12s %-12s %-8s %-8s\n", "Type", "Lexeme", "Line", "Column");
        System.out.println("--------------------------------------------------");

        for (Token token : tokens) {
            System.out.printf("%-12s %-12s %-8d %-8d\n",
                    getTokenTypeString(token.type),
                    token.lexeme, token.line, token.column);
        }
        System.out.println("--------------------------------------------------");
    }
}
