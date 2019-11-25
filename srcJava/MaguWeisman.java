import java.util.ArrayList;
import java.util.TreeSet;
import java.io.PrintWriter;

public class MaguWeisman extends Preprocess{

    private ArrayList<Integer> ans = new ArrayList<Integer>();

    public MaguWeisman(PrintWriter out,String tmp){
        super(out,tmp);
        multiplyExpression();
        printAns(Type.REDUCE_EXPRESSION,ans);
        //printAns(Type.INDEPENDENT_SET,ans);
        //printAns(Type.MAXIMUM_INDEPENDENT_SET,ans);
    }

    public void multiplyExpression(){
        ans.add(0);
        for(int i = 0;i < separate.size();++i){
            ArrayList <Integer> tmp = new ArrayList <Integer>();
            for(int j = 0;j < separate.get(i).adj.size();++j){
                for(int k = 0;k < ans.size();++k){
                    tmp.add(separate.get(i).adj.get(j) | ans.get(k));
                }
            }
            ans.clear();
            ans = new ArrayList<Integer>(simplifyExpression(tmp));
        }
    }

    public ArrayList<Integer> simplifyExpression(ArrayList <Integer> tmp){
        ArrayList <Integer> ret = new ArrayList<Integer>();
        tmp = removeDuplicate(tmp);
        for(int i = 0;i < tmp.size();++i){
            int u = tmp.get(i);
            boolean canPush = true;
            for(int j = 0;j < tmp.size();++j){
                if(i != j){
                    int v = tmp.get(j);
                    if((u | v) == u){
                        canPush = false;
                    }
                }
            }
            if(canPush){
                ret.add(u);
            }
        }
        return ret;
    }

    public ArrayList <Integer> removeDuplicate(ArrayList <Integer> tmp){
        TreeSet <Integer> ts = new TreeSet<Integer>(tmp);
        tmp.clear();
        for(int val : ts){
            tmp.add(val);
        }
        return tmp;
    }
}
