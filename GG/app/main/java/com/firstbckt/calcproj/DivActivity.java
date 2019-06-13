package com.firstbckt.calcproj;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class DivActivity extends AppCompatActivity {
    private TextView SolutionDisp;
    private Button BigB;
    private StringBuilder Sol= new StringBuilder();
    private int num;
    private int num2;
    private int chk=0;





    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_div);
        SolutionDisp=(TextView) findViewById(R.id.Solution);
        BigB=(Button) findViewById(R.id.BigB);
        num=Integer.valueOf(getIntent().getStringExtra("num"));
        num2=Integer.valueOf(getIntent().getStringExtra("num2"));
        SolutionDisp.setText(String.valueOf(num/num2));
    }

    public void onButton(View view){
        if(chk!=1) {
            if(num<num2){
                Sol.append("Result: "+num+"/"+num2);
            }else {
                Div(num, num2);
            }
            SolutionDisp.setText(Sol);
            BigB.setText("Exit");
            chk=1;
        }else{
            finish();
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
    void Div(int num,int num2){
        int[] first= new int[10];
        int l = String.valueOf(num).length();
        SplitToArr(num, first);
        int temp = first[1];
        int chk = 0;
        int pos=1;
        Sol.append("\n"+num+"|"+num2+"\n");
        while (temp<num2){
            pos++;
            temp = temp * 10 + first[pos];
        }
        pos++;
        first[0] = temp / num2;
        int second = num2 * first[0];
        MakeSpace(pos - (String.valueOf(second).length()+1));
        Sol.append(second+"\n");
        second = temp - second;
        temp = ((second)* 10) + first[pos];
        while (pos <= l){
            while (temp<num2){
                if (pos != l){
                    pos++;
                    temp = temp * 10 + first[pos];
                    first[0] *= 10;
                }
                else{
                    second = temp;
                    chk = 1;
                    break;
                }
            }
            first[0] *= 10;
            if (chk == 1){
                break;
            }
            MakeSpace(pos - (String.valueOf(temp).length()));
            Sol.append(temp+"\n");
            first[0] += temp / num2;
            second = num2*(first[0] % 10);
            MakeSpace(pos - (String.valueOf(second).length()));
            Sol.append(second+"\n");
            pos++;
            if (pos <= l){
                temp = ((temp - second) * 10) + first[pos];

            }
            else{
                second = temp - second;
            }
        }
        MakeSpace(l - String.valueOf(second).length());
        Sol.append(second+"\n");
        Sol.append("\n\nResult: "+ first[0]);
        if (second != 0){
            Sol.append("+"+second+"/"+num2+"\n");
        }
    }
}
