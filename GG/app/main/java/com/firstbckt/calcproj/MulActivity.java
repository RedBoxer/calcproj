package com.firstbckt.calcproj;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MulActivity extends AppCompatActivity {
    private StringBuilder Sol= new StringBuilder();
    private TextView SolutionDisp;
    private Button BigB;
    private int num;
    private int num2;
    private int chk=0;
    private int aa=1;
    private int bb=1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mul);
        SolutionDisp=(TextView) findViewById(R.id.MulSol);
        BigB=(Button) findViewById(R.id.DSM);
        num=Integer.valueOf(getIntent().getStringExtra("num"));
        num2=Integer.valueOf(getIntent().getStringExtra("num2"));
        SolutionDisp.setText(String.valueOf(num*num2));

        MakeSpace(20-String.valueOf(num).length());
        if(num>=0) //если число положительное
        {
            Sol.append (" "); //место под знак не нужно и мы заполняем его еще одним пробело
            aa = aa*-1; //у нас были переменные для сохранения информации для знака, это aa и bb. Изначально мы их задали сразу -1 и -1 соответственно. Если число положительное, здесь, когда мы провалились в условие, что число положительное, то мняем знак числа в переменной аа на положительный. Мне показалось так проще
        }
        Sol.append (num+"\n"); //выводим число а вместе со знаком

        MakeSpace(20-String.valueOf(num2).length()); //аналогично предыдущему
        if(num2>=0)
        {
            Sol.append (" ");
            bb = bb*-1;
        }
        Sol.append (num2+"\n");

        num=Math.abs(num); //так как мы будем промежуточный результат выводить без учета знака, то возьмем модули чисел. Заранее сохранив знаки в переменных аа и bb
        num2=Math.abs(num2);

        Sol.append ("  -------------------\n"); //подчеркивание после вывода чисел
    }


    public void onButton(View view){
        if(chk!=1) {
            math(num, num2);
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
    int tenPow(int n){
        int ten = 1;
        for (int i = 1; i <= n; i += 1){
            ten *= 10;
        }
        return ten;
    }

    void math(int num,int num2)
    {
        int tmp=0; //переменная для хранения результата выполнения операций
        int l=String.valueOf(num).length();
        int l2=String.valueOf(num2).length();
        int[] b_array=new int[10];
        int[] tmp_array=new int[10];
        SplitToArr(num2,b_array);
        for(int i=l2; i!=0;i--) //цикл расчета и вывода промежуочных результатов, пробигая по всей длине числа b
        {
            tmp_array[i] = num * b_array[i]; //мы умножаем первое число a последовательно на каждый разряд числа b. Чтобы избежать переполнения int, расширим число a до int
            MakeSpace((21-String.valueOf(tmp_array[i]).length())-(l2-i)); //как и было ранее, красивый вывод, только уже промежуточной строки с особенностью. Здесь нет проверки наличия знака, т.к. мы работаем с НЕотрицательными числами. Начальное значение сдвига строки 21, а не 20. Далее из него вычитаем длину выводимого числа (как и в случаях с а и b), а потом еще вычитаем разряд числа b, т.к. при умножении столбиком каждое следующее действие сдвигается на один разряд влево (не знаю ккак лучше это описать, но думаю и так понятно)
            Sol.append (tmp_array[i]+"\n"); //выводим промежуточное число. обычно для int используется форматированный вывод %d, но мы используем переменную int, а для нее вывод %I64d
        }

        Sol.append ("  -------------------\n"); //когда все промежуточные результаты выведены, рисуем черту

        for(int i=0; i<String.valueOf(num2).length();i++) //т.к. мы хотим показать, что все используемые промежуточные значения были полезны, мы же не выведем просто результат a*b, а проведем сложение, как стандартном случае правила сложения столбиком
        {
            tmp = tmp + (tmp_array[l2-i])*tenPow(i); //в tmp будем складывать все значения. Опять расширим до int, чтобы избежать переполнения int (т.е. в операции мы используем два числа int, то результат сначала будет int, а только потом он попадет в переменную int. А если одна из переменных принципиально будет int, а вторая int, то результат уже будет int на этапе умножения). Здесь используем нашу функцию, описанную выше - возведенеие 10 в степень (т.к. мы просто умножали разряд числа b на число a, настало время учитывать разряд числа b)
        }

        for(int i=0;i<20-String.valueOf(tmp).length();i++) Sol.append (" "); //опять хитрый вывод результата (по аналогии с выводом a и b)
        tmp = tmp*aa*bb; //нужно вспомнить знак результата. Для этого нужно перемножитьднаки исходных множителей, для чего их и сохраняли
        if(tmp>=0) //стандартная уже для нас проверка: нужно ли оставить место под знак "-" при выводе числа
        {
            Sol.append (" "); //если не нужно, то заполняем пробелом
        }
        Sol.append(tmp+"\n");//выводим результат
    }
}
