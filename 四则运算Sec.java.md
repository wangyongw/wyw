# wyw
package com.er.er0;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.net.Uri;
import java.math.BigDecimal;



@SuppressLint("ShowToast")
public class Sec extends Activity {
    private  TextView t1;
    private  EditText e1;
    private  Button b1;
    private  Button b2;
    private  Button b3;
    private  Button b4;
    
    public int num_min;
    public int num_max;
    
    public int num_z=0;
    public int num_w=0;
    
    public boolean flag=false;
    public boolean flag1=false;
    public int num_right=0;
    public int num_wrong=0;
    private int top;
    public float answer;
    private int size=100;
    private String s[]=new String[100];
    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.sec);
        t1=(TextView)findViewById(R.id.textView2);
        e1=(EditText)findViewById(R.id.editText1);
        b1=(Button)findViewById(R.id.button1);
        b2=(Button)findViewById(R.id.button2);
        
        b3=(Button)findViewById(R.id.button3);
        
        b4=(Button)findViewById(R.id.button4);
        
        Intent intent=getIntent();
        Bundle numb=intent.getExtras();
        String n_min=numb.getString("num_min");
        num_min=Integer.parseInt(n_min);
        String n_max=numb.getString("num_max");
        num_max=Integer.parseInt(n_max);
        b1.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View v){
                String s;
                s=e1.getEditableText().toString();
                if(s.length()==0){
                    Toast.makeText(Sec.this, "请输入答案！", Toast.LENGTH_LONG).show();
                }
                else{
                    panduan();
                }
                
            }
        });
        b3.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View v){
                num_w=num_z-num_right-num_wrong;
                exitAlert("本次做题共计"+num_z+"道题，正确"+num_right+"道，错误"+num_wrong+"道，"+num_w+"道未做。\n"+"确定要结束答题吗？");
            }
        });
        b2.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View v){
                e1.setText("");
                chuti();
            }
        });
        b4.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View v){
                flag1=true;
                e1.setText("");
                chuti();
                b4.setVisibility(View.INVISIBLE);
                b2.setVisibility(View.VISIBLE);
                
            }
        });
    }
    
    private void exitAlert(String msg){//退出项选择
        AlertDialog.Builder builder=new AlertDialog.Builder(this);
        builder.setMessage(msg)
        .setCancelable(false)
        .setPositiveButton("确定", new DialogInterface.OnClickListener() {
            
            @Override
            public void onClick(DialogInterface arg0, int arg1) {
                // TODO Auto-generated method stub
                finish();
                
            }
        }).setNegativeButton("取消", new DialogInterface.OnClickListener() {
            
            @Override
            public void onClick(DialogInterface arg0, int arg1) {
                // TODO Auto-generated method stub
                return;
                
            }
        });
        AlertDialog alert=builder.create();
        alert.show();
    }
    private  int suijishu(int num_mi,int num_ma ){//产生随机数
        int x=(int)(num_ma*Math.random()+num_mi);
        return x;
    }
    
    private  void inttochar(int num,char numtochar[]){//整型转换为char型
        int i=0;
        int mid_num;
        char mid_ch;
        do{
            mid_num=num%10;
            numtochar[i]=(char) (mid_num+'0');
            num=num/10;
            i++;
        }while(num!=0);
        
        for(int j=0;j<i/2;j++){
            mid_ch=numtochar[j];
            numtochar[j]=numtochar[i-1-j];
            numtochar[i-1-j]=mid_ch;
        }
        
    }
    private  int length(int num){//计算数的长度
        int i=0;
        do{
            num=num/10;
            i++;
        }while(num!=0);
        return i;
    }
    private  int length_char(char fenshu[]){//计算分数长度
        int i=0;
        do{
            i++;
        }while(fenshu[i]!=')');
        i++;
        return i;
    }
    private  int length_str(char str[]){//计算完整表达式长度
        int i=0;
        do{
            i++;
        }while(str[i]!='\0');
        //i++;
        return i;
    }
    private  void clear_char(char mid_cha[]){//初始化字符数组
        for(int i=0;i<10;i++){
            mid_cha=null;
        }
    }
    private  int fen_huajian(int num_first,int num_second){//求分子分母的最大公约数
        int num_yuf;
        int num_yus;
        int num_yumid = 1;
        for(int i=2;i<=num_first;i++){
            num_yuf=num_first%i;
            num_yus=num_second%i;
            if(num_yuf==0&&num_yus==0){
                num_yumid=i;
            }
        }
        return num_yumid;
    }
    private  void fen(char fe[]){//产生分数
        char num1[]=new char[10];//保存分子
        char num2[]=new char[10];//保存分母
        int num_first;
        int num_second;
        int l1;
        int l2;
        
        int i;
        int num_maxyue;
        if(num_min==0){
            num_first=suijishu(1,num_max);
        }
        else{
            num_first=suijishu(num_min,num_max);
        }
        num_second=suijishu(num_first,num_max);

        num_maxyue=fen_huajian(num_first,num_second);
        
        num_first=num_first/num_maxyue;//分子分母化简
        num_second=num_second/num_maxyue;
        
        
        l1=length(num_first);
        l2=length(num_second);
        
        inttochar(num_first,num1);
        inttochar(num_second,num2);
        
        fe[0]='(';
        for(i=0;i<l1;i++){
            fe[i+1]=num1[i];
        }
        fe[l1+1]='/';
        for(int j=0;j<l2;j++){
            fe[l1+2+j]=num2[j];
        }
        fe[l1+l2+2]=')';
    }
    private  void chuti(){
        int num_yunsuanfu;//运算符个数
        int ch_intorfen;//选择整数或分数
        int number;//保存整数
        int len=0;//保存整个式子长度
        int mid_len=0;//保存单个数长度
        char yunsuanfu[]=new char[3];//保存运算符
        int yunsuan;//产生随机数1-4，用以判断运算符
        //计数（运算数个数）
        char mid_num[]=new char[10];//保存中间产生的数
        char num[]=new char[100];//保存完整式子
        
        
        num_yunsuanfu=suijishu(1,3);//判断产生的运算符为几个
        switch(num_yunsuanfu){
        case 1://产生一个运算符的情况
            int i1=0;
            
            yunsuan=suijishu(1,4);
            switch(yunsuan){
            case 1:
                yunsuanfu[0]='+';
                break;
            case 2:
                yunsuanfu[0]='-';
                break;
            case 3:
                yunsuanfu[0]='*';
                break;
            case 4:
                yunsuanfu[0]='/';
                break;
            }
            
            do{
                ch_intorfen=suijishu(1,2);
                switch(ch_intorfen){
                case 1:
                    do{
                        number=suijishu(num_min,num_max);
                    }while(i1==1&&yunsuanfu[0]=='/'&&number==0);
                    inttochar(number,mid_num);
                    mid_len=length(number);
                    for(int l=0;l<mid_len;l++){
                        num[l+len]=mid_num[l];
                    }
                    
                    break;
                case 2:
                    fen(mid_num);
                    mid_len=length_char(mid_num);
                    for(int l=0;l<mid_len;l++){
                        num[l+len]=mid_num[l];
                    }
                    clear_char(mid_num);
                    break;
                }
                len+=mid_len;
                if(i1<1){
                    num[len]=yunsuanfu[0];
                }
                i1++;
                len++;
            }while(i1!=2);
            len=0;
            break;
            
        case 2://产生两个运算符的情况
            int k2;
            int i2=0;
            for(k2=0;k2<2;k2++){
                yunsuan=suijishu(1,4);
                switch(yunsuan){
                case 1:
                    yunsuanfu[k2]='+';
                    break;
                case 2:
                    yunsuanfu[k2]='-';
                    break;
                case 3:
                    yunsuanfu[k2]='*';
                    break;
                case 4:
                    yunsuanfu[k2]='/';
                    break;
                }
            }
            do{
                ch_intorfen=suijishu(1,2);
                switch(ch_intorfen){
                case 1:
                    do{
                        number=suijishu(num_min,num_max);
                    }while(i2!=0&&yunsuanfu[i2-1]=='/'&&number==0);
                    inttochar(number,mid_num);
                    mid_len=length(number);
                    for(int l=0;l<mid_len;l++){
                        num[l+len]=mid_num[l];
                    }
                    break;
                case 2:
                    fen(mid_num);
                    mid_len=length_char(mid_num);
                    for(int l=0;l<mid_len;l++){
                        num[l+len]=mid_num[l];
                    }
                    clear_char(mid_num);
                    break;
                }
                len+=mid_len;
                if(i2<3){
                    num[len]=yunsuanfu[i2];
                }
                i2++;
                len++;
            }while(i2!=3);
            len=0;
            break;
        case 3:
            int k3;
            int i3=0;
        
            for(k3=0;k3<3;k3++){
                yunsuan=suijishu(1,4);
                switch(yunsuan){
                case 1:
                    yunsuanfu[k3]='+';
                    break;
                case 2:
                    yunsuanfu[k3]='-';
                    break;
                case 3:
                    yunsuanfu[k3]='*';
                    break;
                case 4:
                    yunsuanfu[k3]='/';
                    break;
                }
            }
            
            do{
                ch_intorfen=suijishu(1,2);
                switch(ch_intorfen){
                case 1:
                    do{
                        number=suijishu(num_min,num_max);
                    }while(i3!=0&&yunsuanfu[i3-1]=='/'&&number==0);
                    inttochar(number,mid_num);
                    mid_len=length(number);
                    for(int l=0;l<mid_len;l++){
                        num[l+len]=mid_num[l];
                    }
                
                    break;
                case 2:
                    fen(mid_num);
                    mid_len=length_char(mid_num);
                    
                    for(int l=0;l<mid_len;l++){
                        num[l+len]=mid_num[l];
                    }
                
                    clear_char(mid_num);
                    
                    break;
                }
                len+=mid_len;
                if(i3<3){
                    num[len]=yunsuanfu[i3];
                    
                }
                i3++;
                len++;
            }while(i3!=4);
            len=0;
            break;    
        }
        kuohao(num,num_yunsuanfu);
    }
    private  void kuohao(char num[],int b){
        int wz1=0;//记录第一个运算符的位置
        int wz2=0;//记录第二个运算符的位置
        int wz3=0;//记录第三个运算符的位置
        int i=0;//数组下标
        int kh_wz;//括号位置种类
        int len_str = 0;//表达式长度
        char num2[]=new char[100];
        String Sstr;
        if(b==1){
            len_str=length_str(num);
            for(i=0;i<len_str;i++){
                num2[i]=num[i];
            }
            num2[len_str]='=';
        }
        else{
            switch(b){
            case 2:
                len_str=length_str(num);
                for(;;){
                    if(num[i]=='('){
                        for(;;){
                            if(num[i]==')'){
                                break;
                            }
                            i++;
                        }
                        wz1=i+1;
                        break;
                    }
                    else{
                        if(num[i]=='+'||num[i]=='-'||num[i]=='*'||num[i]=='/'){
                            wz1=i;
                            break;
                        }
                        i++;
                    }
                }
                for(i=wz1+1;;){
                    if(num[i]=='('){
                        for(;;){
                            if(num[i]==')'){
                                break;
                            }
                            i++;
                        }
                        wz2=i+1;
                        break;
                    }
                    else{
                        if(num[i]=='+'||num[i]=='-'||num[i]=='*'||num[i]=='/'){
                            wz2=i;
                            break;
                        }
                        i++;
                    }
                }
                kh_wz=suijishu(0,3);
                switch(kh_wz){
                case 1:
                    num2[0]='(';
                    for(i=0;i<wz2;i++){
                        num2[i+1]=num[i];
                    }
                    num2[wz2+1]=')';  
                    for(i=wz2;i<len_str;i++){
                        num2[i+2]=num[i];
                    }
                    num2[len_str+2]='=';
                    break;
                case 2:
                    for(i=0;i<wz1+1;i++){
                        num2[i]=num[i];
                    }
                    num2[wz1+1]='(';
                    for(i=wz1+1;i<len_str;i++){
                        num2[i+1]=num[i];
                    }
                    num2[len_str+1]=')';
                    num2[len_str+2]='=';
                    break;
                    
                    default:
                    for(i=0;i<len_str;i++){
                        num2[i]=num[i];
                    }
                    num2[len_str]='=';
                    break;
                }
                break;
                    
            case 3:
                len_str=length_str(num);
                for(;;){
                    if(num[i]=='('){
                        for(;;){
                            if(num[i]==')'){
                                break;
                            }
                            i++;
                        }
                        wz1=i+1;
                        break;
                    }
                    else{
                        if(num[i]=='+'||num[i]=='-'||num[i]=='*'||num[i]=='/'){
                            wz1=i;
                            break;
                        }
                        i++;
                    }
                }
                for(i=wz1+1;;){
                    if(num[i]=='('){
                        for(;;){
                            if(num[i]==')'){
                                break;
                            }
                            i++;
                        }
                        wz2=i+1;
                        break;
                    }
                    else{
                        if(num[i]=='+'||num[i]=='-'||num[i]=='*'||num[i]=='/'){
                            wz2=i;
                            break;
                        }
                        i++;
                    }
                }
                for(i=wz2+1;;){
                    if(num[i]=='('){
                        for(;;){
                            if(num[i]==')'){
                                break;
                            }
                            i++;
                        }
                        wz3=i+1;
                        break;
                    }
                    else{
                        if(num[i]=='+'||num[i]=='-'||num[i]=='*'||num[i]=='/'){
                            wz3=i;
                            break;
                        }
                        i++;
                    }
                }
                kh_wz=suijishu(0,9);
                switch(kh_wz){
                case 1:
                    num2[0]='(';
                    for(i=0;i<wz2;i++){
                        num2[i+1]=num[i];
                    }
                    num2[wz2+1]=')';  
                    for(i=wz2;i<len_str;i++){
                        num2[i+2]=num[i];
                    }
                    num2[len_str+2]='=';
                    break;
                case 2:
                    for(i=0;i<wz1+1;i++){
                        num2[i]=num[i];
                    }
                    num2[wz1+1]='(';
                    for(i=wz1+1;i<wz3;i++){
                        num2[i+1]=num[i];
                    }
                    num2[wz3+1]=')';
                    for(i=wz3;i<len_str;i++){
                        num2[i+2]=num[i];
                    }
                    num2[len_str+2]='=';
                    break;
                case 3:
                    for(i=0;i<wz2+1;i++){
                        num2[i]=num[i];
                    }
                    num2[wz2+1]='(';
                    for(i=wz2+1;i<len_str;i++){
                        num2[i+1]=num[i];
                    }
                    num2[len_str+1]=')';
                    num2[len_str+2]='=';
                    break;
                case 4:
                    num2[0]='(';
                    num2[1]='(';
                    for(i=0;i<wz2;i++){
                        num2[i+2]=num[i];
                    }
                    num2[wz2+2]=')';
                    for(i=wz2;i<wz3;i++){
                        num2[i+3]=num[i];
                    }
                    num2[wz3+3]=')';
                    for(i=wz3;i<len_str;i++){
                        num2[i+4]=num[i];
                    }
                    num2[len_str+4]='=';
                    break;
                case 5:
                    num2[0]='(';
                    for(i=0;i<wz1+1;i++){
                        num2[i+1]=num[i];
                    }
                    num2[wz1+2]='(';
                    for(i=wz1+1;i<wz3;i++){
                        num2[i+2]=num[i];
                    }
                    num2[wz3+2]=')';
                    num2[wz3+3]=')';
                    for(i=wz3;i<len_str;i++){
                        num2[i+4]=num[i];
                    }
                    num2[len_str+4]='=';
                    break;
                case 6:
                    for(i=0;i<wz1+1;i++){
                        num2[i]=num[i];
                    }
                    num2[wz1+1]='(';
                    num2[wz1+2]='(';
                    for(i=wz1+1;i<wz3;i++){
                        num2[i+2]=num[i];
                    }
                    num2[wz3+2]=')';
                    for(i=wz3;i<len_str;i++){
                        num2[i+3]=num[i];
                    }
                    num2[len_str+3]=')';
                    num2[len_str+4]='=';
                    break;
                case 7:
                    for(i=0;i<wz1+1;i++){
                        num2[i]=num[i];
                    }
                    num2[wz1+1]='(';
                    for(i=wz1+1;i<wz2+1;i++){
                        num2[i+1]=num[i];
                    }
                    num2[wz2+2]='(';
                    for(i=wz2+1;i<len_str;i++){
                        num2[i+2]=num[i];
                    }
                    num2[len_str+2]=')';
                    num2[len_str+3]=')';
                    num2[len_str+4]='=';
                    break;
                case 8:
                    num2[0]='(';
                    for(i=0;i<wz2;i++){
                        num2[i+1]=num[i];
                    }
                    num2[wz2+1]=')';
                    num2[wz2+2]=num[wz2];
                    num2[wz2+3]='(';
                    for(i=wz2+1;i<len_str;i++){
                        num2[i+3]=num[i];
                    }
                    num2[len_str+3]=')';
                    num2[len_str+4]='=';
                    break;
                    default:
                        for(i=0;i<len_str;i++){
                            num2[i]=num[i];
                        }
                        num2[len_str]='=';
                        break;
                }
                break;
            }
            
            
            
        }
        Sstr=String.valueOf(num2);
        char2str(num2,Sstr);
    }
    private  void char2str(char str[],String Sstr){
        int l;
        int k=0;
        char ww;
        String str1[]=new String[100];
        String post[]=new String[100];
        l=length_str(str);
        for(int i=0;i<l;i++){
            ww=str[i];
            switch (ww){
            case '=':
                str1[k]="=";
                k++;
                break;
            case '(':
                str1[k]="(";
                k++;
                break;
            case '+':
                str1[k]="+";

                k++;
                break;
            case '-':
                str1[k]="-";
                k++;
                break;
            case '*':
                str1[k]="*";
                k++;
                break;
            case '/':
                str1[k]="/";
                k++;
                break;
            case ')':
                str1[k]=")";
                k++;
                break;

            default:
                int ss=i;
                if (str[ss]=='0'){
                    
                    str1[k]="0";
                }
                if (str[ss]=='1'){
                    str1[k]="1";
                }
                if (str[ss]=='2'){
                    str1[k]="2";
                }
                if (str[ss]=='3'){
                    str1[k]="3";
                }
                if (str[ss]=='4'){
                    str1[k]="4";
                }
                else if (str[ss]=='5'){
                    str1[k]="5";
                }
                if (str[ss]=='6'){
                    str1[k]="6";
                }
                if (str[ss]=='7'){
                    str1[k]="7";
                }
                if (str[ss]=='8'){
                    str1[k]="8";
                }
                if (str[ss]=='9'){
                    str1[k]="9";
                }
                for (ss=ss+1;;ss++){

                    if (str[ss]=='0'){
                        
                        str1[k]+="0";
                    }
                    else if (str[ss]=='1'){
                        str1[k]+="1";
                    }
                    else if (str[ss]=='2'){
                        str1[k]+="2";
                    }
                    else if (str[ss]=='3'){
                        str1[k]+="3";
                    }
                    else if (str[ss]=='4'){
                        str1[k]+="4";
                    }
                    else if (str[ss]=='5'){
                        str1[k]+="5";
                    }
                    else if (str[ss]=='6'){
                        str1[k]+="6";
                    }
                    else if (str[ss]=='7'){
                        str1[k]+="7";
                    }
                    else if (str[ss]=='8'){
                        str1[k]+="8";
                    }
                    else if (str[ss]=='9'){
                        str1[k]+="9";
                    }
                    else{
                        i=ss-1;
                        break;
                    }
                }
                k++;
            }
        }
        mid_post(str1,post,Sstr);
    }
    private  void clearstack(){//初始化栈顶指针
        top=-1;
    }
    private  int emptystack(){
        if (top<0){
            return 1;
        }
        else{
            return 0;
        }
    }
    private  String gettop(){
        if (emptystack()==1){
            return null;
        } 
        else{
            return s[top];
        }
    }
    private  void Push(String mid_v){
        if (top>=size-1){
        } 
        else{
            top++;
            s[top]=mid_v;
        }
    }
    private  String pop(){
        if (emptystack()==1){
            return null;
        } 
        else{
            top--;
            return s[top+1];
        }
    }
    private  int precede(String x,String y){
        int x1=0;
        int y1=0;
        if (x=="#")
        {
            x1=0;
        }
        if (x=="(")
        {
            x1=1;
        }
        if (x=="+")
        {
            x1=2;
        }
        if (x=="-")
        {
            x1=2;
        }
        if (x=="*")
        {
            x1=3;
        }
        if (x=="/")
        {
            x1=3;
        }

        
        if (y=="#")
        {
            y1=0;
        }
        if (y=="+")
        {
            y1=2;
        }
        if (y=="-")
        {
            y1=2;
        }
        if (y=="*")
        {
            y1=3;
        }
        if (y=="/")
        {
            y1=3;
        }
        if (y=="(")
        {
            y1=4;
        }
        if(x1>=y1){
            return 1;
        }
        else{
            return 0;
        }
    }
    private  void mid_post(String str[],String post[],String Sstr){
        int i=0;
        int j=0;
        String x;
        clearstack();
        Push("=");
        do{
            x=str[i];
            i++;
            if (x=="="){
                while (emptystack()==0){
                    post[j++]=pop();
                }
            }
            else if (x==")"){
                while (gettop()!="("){
                    post[j++]=pop();
                }
                pop();
            }
            else if (x=="+"||x=="-"||x=="*"||x=="/"||x=="("){
                while (precede(gettop(),x)==1){
                    post[j++]=pop();
                }
                Push(x);
            }
            else{
                post[j++]=x;
            }
        } while (x!="=");
        postcount(post,Sstr);
    }
    private  void postcount(String post[],String Sstr){
        
        
        int i=0;
        float z,a,b=0;
        
        
        String x;
        String xx;
        clearstack();
        while(post[i]!="="){
            x=post[i];
            
            if(x=="+"){
                b=Float.valueOf(pop());
                a=Float.valueOf(pop());
                z=a+b;
                xx=String.valueOf(z);
                Push(xx);
            }
            else if(x=="-"){
                b=Float.valueOf(pop());
                a=Float.valueOf(pop());
                z=a-b;
                xx=String.valueOf(z);
                Push(xx);
            }
            else if(x=="*"){
                b=Float.valueOf(pop());
                a=Float.valueOf(pop());
                z=a*b;
                xx=String.valueOf(z);
                Push(xx);
            }
            else if(x=="/"){
                b=Float.valueOf(pop());
                a=Float.valueOf(pop());
                z=a/b;
                xx=String.valueOf(z);
                Push(xx);
            }
            else{
                Push(x);
            }
            i++;
        }
        if(emptystack()==0){
            x=gettop();
            answer=Float.parseFloat(x);
            BigDecimal c=new BigDecimal((float)answer);
            answer = c.setScale(2,  BigDecimal.ROUND_HALF_UP).floatValue(); 
        }
        if(answer<0){
            chuti();
        }
        else{
            num_z++;
            flag=true;
            t1.setText(Sstr);
            
        }
    }
    private void panduan(){
        String an;
        float b;
        an=e1.getText().toString();
        b=Float.parseFloat(an);
        
        if(b==answer){
            if(flag){
                num_right++;
            }
            Toast.makeText(Sec.this, "回答正确！", Toast.LENGTH_LONG).show();
        }
        else
        {
            if(flag){
                num_wrong++;
            }
            if(flag1){
                Toast.makeText(Sec.this, "回答错误！正确答案为："+answer, Toast.LENGTH_LONG).show();
            }
            
        }
        flag=false;
    }
}
