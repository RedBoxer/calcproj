package com.firstbckt.calcproj;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class SumActivity extends AppCompatActivity {
    private StringBuilder Sol= new StringBuilder();
    private TextView SolutionDisp;
    private Button BigB;
    private int num;
    private int num2;
    private int chk=0;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sum);
        SolutionDisp=(TextView) findViewById(R.id.Solut);
        BigB=(Button) findViewById(R.id.BigB2);
        num=Math.abs(Integer.valueOf(getIntent().getStringExtra("num")));
        num2=Math.abs(Integer.valueOf(getIntent().getStringExtra("num2")));
        if(num<num2){
            chk=num;
            num=num2;
            num2=chk;
            chk=0;
        }
        SolutionDisp.setText(String.valueOf(num+num2));
    }

    public void onButton(View view){
        if(chk!=1) {
            Sum(num, num2);
            SolutionDisp.setText(Sol);
            BigB.setText("Exit");
            chk=1;
        }else{
            finish();
        }
    }
    void Sum(int num, int num2){
        int core=num2;
        int[] ost=new int[11];
        int[] first=new int[11];
        int[] second=new int[11];
        int l=String.valueOf(num).length();
        int pos = l;
        int result = 0;
        first[0] = 0;
        SplitToArr(num, first);
        for (int i=l;i!=0;i--){
            if(core!=0) {
                second[i] = core % 10;
                core /= 10;
            }
        }
        while (pos != 0){
            if (first[pos] + second[pos] >= 10){
                ost[pos - 1] = 1;
                core=first[pos]+second[pos];
                core%=10;
                core*=tenPow(l-pos);
                result += core;
                first[pos - 1] += 1;
            }
            else{
                core=first[pos]+second[pos];
                core*=tenPow(l-pos);
                result += core;
            }
            pos -= 1;
        }
        if (first[0] > 0){
            result += (tenPow(l))*first[0];
        }
        Disp_Sol(num, num2, result, ost);
        Sol.append("\n"+result+"\n");
    }
    void Disp_Sol(int num, int num2, int result, int p[]){
        Sol.append("\n");
        int l=String.valueOf(num).length();
        if (String.valueOf(result).length() > l){
            MakeSpace(1);
            for (int i = 1; i < l; i += 1){
                if (p[i] != 0){
                    Sol.append(p[i]);
                }
                else{
                    MakeSpace(1);
                }
            }
            Sol.append("\n");
            MakeSpace(1);
            Sol.append(num+"\n");
            MakeSpace((l - String.valueOf(num2).length())+1);
            Sol.append(num2+"\n");
            for (int i = 0; i < l + 1; i += 1){
                Sol.append("-");
            }
        }
        else{
            for (int i = 1; i < l; i += 1){
                if (p[i] != 0){
                    Sol.append(p[i]);
                }
                else{
                    MakeSpace(1);
                }
            }
            Sol.append("\n");
            Sol.append(num+"\n");
            MakeSpace(l - String.valueOf(num2).length());
            Sol.append(num2+"\n");
            for (int i = 0; i < l; i += 1){
                Sol.append("-");
            }
        }

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
