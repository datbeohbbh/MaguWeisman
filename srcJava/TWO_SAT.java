import java.util.ArrayList;
import java.io.PrintWriter;

public class TWO_SAT extends Preprocess {

    private ArrayList<Integer> ans = new ArrayList<Integer>();

    public TWO_SAT(PrintWriter out,String tmp){
        super(out,tmp);
        assignLogic();
        //printAns(Type.MAXIMUM_INDEPENDENT_SET,ans);
    }

    public void assignLogic(){
        for(int mask = 1;mask < (1 << (highestbit + 1));++mask){
            int f = 1;
            int[] msk = new int[(1 << highestbit) + 1];
            for(int i = 0;i <= highestbit;++i){
                msk[1 << i] = (mask >> i) & 1;
            }
            for(int i = 0;i < separate.size();++i){
                int cur = 0;
                for(int j = 0;j < separate.get(i).adj.size();++j){
                    int u = separate.get(i).adj.get(j);
                    cur |= (msk[u] ^ 1);
                }
                f &= cur;
            }
            if(f == 1 && highestbit - Integer.bitCount(mask ^ ((1 << (highestbit + 1)) - 1)) > 0){
                ans.add(mask ^ ((1 << (highestbit + 1)) - 1));
            }
        }
    }
}
