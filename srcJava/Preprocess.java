import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Stack;

public class Preprocess {

    private PrintWriter out;
    private String s = new String();
    private Stack<Integer> stk = new Stack<Integer>();
    private int len = 0;
    protected int highestbit = 0;
    protected ArrayList <Vertices> separate = new ArrayList <Vertices> ();

    public Preprocess(PrintWriter out,String s){
        this.out = new PrintWriter(out);
        this.s = s;
        creatSeparate();
    }

    public void creatSeparate(){
        int n = (s == null ? 0 : s.length());
        for(int i = 0;i < n;++i){
            len += (s.charAt(i) == '*' ? 1 : 0);
            highestbit = Math.max(highestbit,(int)(s.charAt(i) - 'a'));
        }
        ++len;
        s += "*";
        for(int i = 0;i < len;++i){
            separate.add(new Vertices());
        }
        int cur = -1;
        for(int i = 0;i <= n;++i){
            if(s.charAt(i) != '(' && s.charAt(i) != '+' && s.charAt(i) != ')') {
                if (s.charAt(i) != '*') {
                    stk.push((Integer) toMask(s.charAt(i)));
                } else{
                    ++cur;
                    while (!stk.empty()) {
                        separate.get(cur).adj.add(stk.peek());
                        stk.pop();
                    }
                }
            }
        }
    }

    public int getMask(int mask,int j){
        return (mask >> j) & 1;
    }

    public boolean chk(int mask,int j,Type g,int mx){
        if(g.ordinal() < 2){
            return getMask(mask,j) == g.ordinal();
        } else {
            return highestbit - Integer.bitCount(mask) + 1 == mx && getMask(mask,j) == 0;
        }
    }

    public void printAns(Type g,ArrayList <Integer> ans){
        //out.println(g + ":\n");
        int mx = -1;
        if(g.ordinal() == 2){
            for(int mask : ans){
                mx = Math.max(mx,highestbit - Integer.bitCount(mask) + 1);
            }
        }
        ArrayList <Vertices> pr = new ArrayList<Vertices>();
        for(int i = 0;i < ans.size();++i){
            int mask = ans.get(i);
            Vertices ar = new Vertices();
            for(int j = 0;j <= highestbit;++j){
                if(chk(mask,j,g,mx)){
                    ar.adj.add(j);
                }
            }
            if(!ar.adj.isEmpty()) {
                pr.add(ar);
            }
        }
        for(int i = 0;i < pr.size();++i){
            Vertices ar = pr.get(i);
            for(int j = 0;j < ar.adj.size();++j){
                out.print(toChar(ar.adj.get(j)));
                if(j < ar.adj.size() - 1){
                    out.print("*");
                }
            }
            if(i != pr.size() - 1){
                out.print("+");
            }
        }
        out.println("\n");
    }

    public int toMask(char c){
        return 1 << ((int)(c - 'a'));
    }

    public char toChar(int c){
        return (char)(c + 'a');
    }

    protected class Vertices{
        protected ArrayList <Integer> adj;
        public Vertices(){
            adj = new ArrayList<Integer>();
        }
    }
}

