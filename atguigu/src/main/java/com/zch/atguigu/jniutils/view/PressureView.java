package com.zch.atguigu.jniutils.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

/**
 * Created by zch on 2017/2/25.
 */

public class PressureView extends View {

    private int mPressure;//锅炉压力值
    private Paint mPaint;

    public PressureView(Context context) {
        super(context);

        mPaint = new Paint();
        mPaint.setAntiAlias(true);//设置抗锯齿
        mPaint.setTextSize(25);
    }

    public void setPressure(int pressure) {
        this.mPressure = pressure;
        postInvalidate();//onDraw()执行
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        if (mPressure > 220) {
            //1.如果压力值大于220，就绘制文本，显示锅炉爆炸了，刚哥快跑
            canvas.drawText("刚哥快跑！！，要爆了！", 10, getHeight() / 2, mPaint);
        } else {
            //2.正常和提示的情况
            //设置背景颜色为灰色
            mPaint.setColor(Color.GRAY);
            canvas.drawRect(10, 10, 60, 260, mPaint);

            //2.1如果是小于200正常显示，并且设置画笔颜色，绿色
            if (mPressure < 200) {
                mPaint.setColor(Color.GREEN);
                canvas.drawRect(10, 260 - mPressure, 60, 260, mPaint);
            } else if (mPressure >= 200) {
                //2.2如果是大于200警示给看护者，并且设置画笔颜色，红色
                mPaint.setColor(Color.RED);
                canvas.drawRect(10, 260 - mPressure, 60, 260, mPaint);
            }
        }
    }
}
