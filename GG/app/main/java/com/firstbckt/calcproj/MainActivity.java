package com.firstbckt.calcproj;


import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;


import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private EditText First;
    private EditText Second;
    private TextView Err;



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
            if(String.valueOf(First.getText()).length()>9 ||String.valueOf(Second.getText()).length()>9 ){
                Err.setText("Entered numbers are too long(max 9 digits)");
            }else {
                goToActivity(SumActivity.class);
            }
        }else{
            Err.setText("Enter numbers first!");
        }
    }

    public void Sub(View view){
        if(checkField(First)&&checkField(Second)){
            if(String.valueOf(First.getText()).length()>9 ||String.valueOf(Second.getText()).length()>9 ){
                Err.setText("Entered numbers are too long(max 9 digits)");
            }else {
                goToActivity(SubActivity.class);
            }
        }else{
            Err.setText("Enter numbers first!");
        }
    }

    public void Mul(View view){
        if(checkField(First)&&checkField(Second)){
            if(String.valueOf(First.getText()).length()>9 ||String.valueOf(Second.getText()).length()>9 ){
                Err.setText("Entered numbers are too long(max 9 digits)");
            }else {
                goToActivity(MulActivity.class);
            }
        }else{
            Err.setText("Enter numbers first!");
        }
    }

    public void Div(View view){
        if(checkField(First)&&checkField(Second)){
            if(String.valueOf(First.getText()).length()>9 ||String.valueOf(Second.getText()).length()>9 ){
                Err.setText("Entered numbers are too long(max 9 digits)");
            }else {
                if(Integer.valueOf(String.valueOf(First.getText()))==0||Integer.valueOf(String.valueOf(Second.getText()))==0){
                    Err.setText("Can not divide by zero");
                }
                goToActivity(DivActivity.class);
            }
        }else {
            Err.setText("Enter numbers first");
        }
    }

    void goToActivity(Class str){
        Err.setText("");
        Intent intent = new Intent(this, str);
        intent.putExtra("num", First.getText().toString());
        intent.putExtra("num2", Second.getText().toString());
        startActivity(intent);
    }

    boolean checkField(EditText Field){
        if(Field.getText().toString().length()!=0){
            return true;
        }
        return false;
    }
}
