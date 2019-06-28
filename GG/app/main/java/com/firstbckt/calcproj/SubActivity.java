package com.firstbckt.calcproj;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

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
       // if(num<num2){
       //     chk=num;
            num=num2;
            num2=chk;
            //   chk=0;
       // }
        SolutionDisp.setText(String.valueOf(num-num2));
    }

    public void onButton(View view){
        if(chk!=1) {
            //Sub(num, num2);
            SolutionDisp.setText(Sol);
            BigB.setText("Exit");
            chk=1;
        }else{
            finish();
        }
    }
}
