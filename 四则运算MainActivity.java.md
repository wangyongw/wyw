# wyw
package com.er.er0;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.content.Intent;
import android.view.View.OnClickListener;
import android.view.View;

public class MainActivity extends Activity {
    
    private EditText e_min;
    private EditText e_max;
    private Button b1;
    private Button b2;
    private MenuInflater act;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        e_min=(EditText)findViewById(R.id.editText1);
        e_max=(EditText)findViewById(R.id.editText2);
        b1=(Button)findViewById(R.id.button1);
        b2=(Button)findViewById(R.id.button2);
        act=new MenuInflater(this);
        
        b1.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View v){
            
                String num_min=e_min.getText().toString();
                String num_max=e_max.getText().toString();
                Bundle n_min=new Bundle();
                Bundle n_max=new Bundle();
                Intent intent = new Intent(MainActivity.this,Sec.class);
                if(num_min.length()==0||num_max.length()==0){
                    Toast.makeText(MainActivity.this, "请输入数值范围！", Toast.LENGTH_LONG).show();
                }
                else{
                    n_min.putString("num_min", num_min);
                    n_max.putString("num_max", num_max);
                    intent.putExtras(n_min);
                    intent.putExtras(n_max);
                    startActivity(intent);
                }
                
                
            }
        });
        b2.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View v){
                exitAlert("真的要退出吗？");
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        act.inflate(R.menu.main, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
        if(item.getItemId()==R.id.action_settings){
            exitAlert("真的要退出吗？");
        }
        return true;
    }
    private void exitAlert(String msg){
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

}
