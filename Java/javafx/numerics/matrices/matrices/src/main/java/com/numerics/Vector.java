package com.numerics;

public class Vector{
    
    private double x1;
    private double x2;
    private double x3;

    public Vector(double x1, double x2, double x3){
        this.x1 = x1;
        this.x2 = x2;
        this.x3 = x3;
    }

    public double getX1(){
        return x1;
    }

    public double getX2(){
        return x2;
    }

    public double getX3(){
        return x3;
    }

    @Override
    public String toString(){
        return "[" +x1 + ',' + x2 + ',' +x3 + "]";
    }

}