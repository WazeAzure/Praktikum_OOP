import java.util.*;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        this.tasks = new ArrayList<Task>();
    };

    public void addTask(Task newTask){
        this.tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            for (Task task : this.tasks) {
                Thread.sleep(task.getTime());
                synchronized (task) {
                    task.setStatus("done");
                    task.notify();
                }
            }
        } catch (InterruptedException e) {
            System.out.println("Worker Error!");
        }
    }
}