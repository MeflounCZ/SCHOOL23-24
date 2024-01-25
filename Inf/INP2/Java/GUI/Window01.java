import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Window01 extends JFrame{

    JPanel panelHugo, panelHenri;
    JTextField hugoEar, hugoMouth, henriEar, henriMouth;
    JButton hugoSay, henriSay;

    class Backend implements ActionListener{
        public void actionPerformed(ActionEvent e){
            //TODO: implement
        }
    }
    public Window01(String title){
        super(title);

        panelHugo = new JPanel();
        panelHenri = new JPanel();

        hugoEar = new JTextField();
        hugoMouth = new JTextField();
        henriEar = new JTextField();
        henriMouth = new JTextField();

        hugoSay = new JButton("Talk to Henri");
        henriSay = new JButton("Talk to Hugo");



        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.setLayout(new GridLayout(2, 1));
        this.add(panelHugo);
        panelHugo.setBorder(BorderFactory.createTitledBorder("Hugo"));
        this.add(panelHenri);
        panelHenri.setBorder(BorderFactory.createTitledBorder("Henri"));
        panelHugo.setLayout(new GridLayout(2, 3));
        panelHenri.setLayout(new GridLayout(2, 3));

        panelHugo.add(new JLabel("Ear: "));
        panelHenri.add(new JLabel("Ear: "));

        panelHugo.add(hugoEar);
        panelHenri.add(henriEar);

        panelHugo.add(new JLabel(""));
        panelHenri.add(new JLabel(""));

        panelHugo.add(new JLabel("Mouth: "));
        panelHenri.add(new JLabel("Mouth: "));

        panelHugo.add(hugoMouth);
        panelHenri.add(henriMouth);

        panelHugo.add(hugoSay);
        panelHenri.add(henriSay);



        this.pack();
        this.setLocationRelativeTo(null);
        this.setVisible(true);

    }


    public static void main(String[] args){
        new Window01("First window");
    }
}