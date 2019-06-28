package com.firstbckt.calcproj;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import static java.lang.Integer.max;

public class SubActivity extends AppCompatActivity {

    private StringBuilder Sol= new StringBuilder();
    private TextView SolutionDisp;
    private Button BigB;
    private int num;
    private int num2;
    private int chk=0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);
        SolutionDisp=(TextView) findViewById(R.id.SubSol);
        BigB=(Button) findViewById(R.id.DispSub);
        num=Integer.valueOf(getIntent().getStringExtra("num"));
        num2=Integer.valueOf(getIntent().getStringExtra("num2"));
        SolutionDisp.setText(String.valueOf(num-num2));
    }

    public void onButton(View view){
        if(chk!=1) {
            Sub(num, num2);
            SolutionDisp.setText(Sol);
            BigB.setText("Exit");
            chk=1;
        }else{
            finish();
        }
    }

    void Sub(int num, int num2){
        int n = num;
        int n2 = num2;
        int chk = 0;
        if (num < num2){
            n = num2;
            n2 = num;
            chk = 1;
        }
        int core=n2;
        int[] ost=new int[11];
        int[] first=new int[11];
        int[] second=new int[11];
        int l = String.valueOf(n).length();
        int pos = l;
        int result = 0;
        first[0] = 0;
        SplitToArr(n, first);
        for (int i = 1; i <= l; i++){
            ost[i] = 0;
            second[i] = 0;
        }
        for (int i=l;i!=0;i--){
            if(core!=0) {
                second[i] = core % 10;
                core /= 10;
            }
        }
        while (pos != 0){
            if (first[pos] - second[pos] < 0){
                ost[pos - 1] = 1;
                result += ((first[pos]+10) - second[pos])*tenPow(l - pos);
                first[pos - 1] -= 1;
            }
            else{
                result += (first[pos] - second[pos]) * tenPow(l - pos);
            }
            pos--;
        }
        if (chk == 1){
            result *= -1;
        }
        Disp_Sub(num, num2, result, ost);
    }

    void Disp_Sub(int num, int num2, int result, int[]p){
        int l = Max(String.valueOf(num).length(), String.valueOf(num2).length());
        for (int i = 1; i < l; i += 1){
            if (p[i] != 0 && num>num2){
                Sol.append("*");
            }
            else{
                MakeSpace(1);
            }
        }
        Sol.append("\n");
        if (num < num2){
            MakeSpace(l-String.valueOf(num).length());
        }
        Sol.append(num+"\n");
        MakeSpace(l - String.valueOf(num2).length());
        Sol.append(num2+"\n");
        for (int i = 0; i < l; i += 1){
            Sol.append("-");
        }
        Sol.append("\n");
        if (result >= 0){
            MakeSpace(l - String.valueOf(result).length());
        }
        else{
            MakeSpace((l - String.valueOf(result*-1).length()) - 1);
        }
        Sol.append(result+"\n");
    }

    int Max(int num, int num2){
        if(num>=num2){
            return num;
        }
        return num2;
    }
    void MakeSpace(int n){
        if (n < 0){
            return;
        }
        for (int i = 1; i <= n; i++){
            Sol.append(" ");
        }
    }
    void SplitToArr(int num, int out[]){
        int  l=String.valueOf(num).length();
        int temp = num;
        for (int i = l; i > 0; i--){
            out[i] = temp % 10;
            temp = temp / 10;
        }
    }
    int tenPow(int n){
        int ten = 1;
        for (int i = 1; i <= n; i += 1){
            ten *= 10;
        }
        return ten;
    }
}
