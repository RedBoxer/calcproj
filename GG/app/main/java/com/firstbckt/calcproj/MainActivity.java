package com.firstbckt.calcproj;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private EditText First;
    private EditText Second;
    private TextView Err;

    boolean checkField(EditText Field){
        if(Field.getText().toString().length()!=0){
            return true;
        }
        return false;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        First=(EditText) findViewById(R.id.First);
        Second=(EditText) findViewById(R.id.Second);
        Err=(TextView) findViewById(R.id.Error);
    }

    public void Sum(View view){
        if(checkField(First)&&checkField(Second)){
            Intent intent = new Intent(this, SumActivity.class);
            intent.putExtra("num", First.getText().toString());
            intent.putExtra("num2", Second.getText().toString());
            startActivity(intent);
        }else{
            Err.setText("Enter numbers first!");
        }
    }

    public void Div(View view){
        if(checkField(First)&&checkField(Second)){
            Intent intent = new Intent(this, DivActivity.class);
            intent.putExtra("num", First.getText().toString());
            intent.putExtra("num2", Second.getText().toString());
            startActivity(intent);
        }else {
            Err.setText("Enter numbers first!");
        }
    }
}
